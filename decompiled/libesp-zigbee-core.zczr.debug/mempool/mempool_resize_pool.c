/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mempool.o -> mempool_resize_pool
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mempool_resize_pool(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.c",0x6e,
                  "mempool_resize_pool",0x10000);
  }
  else if (param_2 != 0) {
    uVar1 = mm_realloc(*(undefined4 *)(param_1 + 0xc),*(undefined2 *)(param_1 + 2));
    *(undefined4 *)(param_1 + 0xc) = uVar1;
    uVar3 = param_2 + 7 >> 3;
    uVar1 = mm_realloc(*(undefined4 *)(param_1 + 8),uVar3,1);
    *(undefined4 *)(param_1 + 8) = uVar1;
    uVar2 = (uint)*(ushort *)(param_1 + 4);
    if (uVar2 < param_2) {
      memset((void *)(*(int *)(param_1 + 0xc) + uVar2 * *(ushort *)(param_1 + 2)),0,
             (uint)*(ushort *)(param_1 + 2) * (param_2 - uVar2));
      uVar2 = *(ushort *)(param_1 + 4) + 7 >> 3;
      memset((void *)(*(int *)(param_1 + 8) + uVar2),0,uVar3 - uVar2);
    }
    goto _L0;
  }
  mempool_deinit_pool();
_L0:
  *(short *)(param_1 + 4) = (short)param_2;
  return;
}

