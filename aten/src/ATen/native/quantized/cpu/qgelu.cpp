#include <ATen/ATen.h>
#include <ATen/NativeFunctions.h>
#include <torch/library.h>
#include <ATen/native/TensorIterator.h>
#include <ATen/native/cpu/Loops.h>
#include <ATen/quantized/Quantizer.h>
#include <ATen/native/quantized/cpu/quantized_ops.h>
#include <c10/util/irange.h>
#include <caffe2/utils/threadpool/pthreadpool-cpp.h>

#include <algorithm>

namespace at {
namespace native {

DEFINE_DISPATCH(qgelu_stub);

Tensor gelu_quantized_cpu(const Tensor& qx, int64_t approximate) {
  Tensor qy;
  qgelu_stub(qx.device().type(), qx, qy, approximate);
  return qy;
}
}}  // namespace at::native
