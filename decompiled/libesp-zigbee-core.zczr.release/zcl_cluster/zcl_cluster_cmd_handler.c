/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_cluster.o -> zcl_cluster_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_cluster_cmd_handler(int param_1)

{
  int iVar1;
  size_t __size;
  void *pvVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == 0) {
    param_1 = __assert_func(0,0,0);
  }
  iVar1 = zcl_cluster_template_find
                    (*(undefined2 *)(param_1 + 0x16),((*(byte *)(param_1 + 0x1a) & 8) != 0) + '\x01'
                    );
  if (iVar1 != 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x10);
    if (*(short *)(param_1 + 0x16) < 0) {
      if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
        return 0x81;
      }
      __size = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      pvVar2 = calloc(1,__size);
      if ((pvVar2 == (void *)0x0) && (__size != 0)) {
        return 0x89;
      }
      zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,__size,pvVar2);
      uVar3 = (**(code **)(iVar1 + 0x10))(param_1,pvVar2,__size,*(code **)(iVar1 + 0x10));
      mm_free(pvVar2);
      return uVar3;
    }
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00010264. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (*UNRECOVERED_JUMPTABLE)(param_1);
      return uVar3;
    }
  }
  return 0x81;
}

