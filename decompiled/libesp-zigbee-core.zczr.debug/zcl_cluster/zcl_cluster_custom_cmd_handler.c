/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_cluster.o -> zcl_cluster_custom_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_cluster_custom_cmd_handler(int param_1,int param_2)

{
  undefined4 uVar1;
  void *unaff_s2;
  size_t unaff_s3;
  undefined2 auStack_22 [7];
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_cluster.c",0x7e,
                  "zcl_cluster_custom_cmd_handler","packet");
  }
  else {
    if (param_2 == 0) {
      return 0x81;
    }
    if (*(int *)(param_2 + 0x10) == 0) {
      return 0x81;
    }
    unaff_s3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    unaff_s2 = calloc(1,unaff_s3);
    auStack_22[0] = 0;
    if (unaff_s2 != (void *)0x0) goto _L0;
  }
  if (unaff_s3 != 0) {
    return 0x89;
  }
_L0:
  af_read_bytes(*(undefined4 *)(param_1 + 0x24),auStack_22,unaff_s3,unaff_s2);
  uVar1 = (**(code **)(param_2 + 0x10))(param_1,unaff_s2,unaff_s3,*(code **)(param_2 + 0x10));
  mm_free(unaff_s2);
  return uVar1;
}

