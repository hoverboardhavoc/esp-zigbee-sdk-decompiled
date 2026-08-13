/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mempool.o -> mempool_deinit_pool
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mempool_deinit_pool(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint extraout_a1;
  uint uVar3;
  uint uVar4;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      mm_free();
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    if (*(int *)(param_1 + 8) != 0) {
      mm_free();
      *(undefined4 *)(param_1 + 8) = 0;
    }
    return;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.c",0x5f,
                        "mempool_deinit_pool",0x10000);
  if (iVar1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.c",0x6e,
                  "mempool_resize_pool",0x10000);
  }
  else if (extraout_a1 != 0) {
    uVar2 = mm_realloc(*(undefined4 *)(iVar1 + 0xc),*(undefined2 *)(iVar1 + 2));
    *(undefined4 *)(iVar1 + 0xc) = uVar2;
    uVar4 = extraout_a1 + 7 >> 3;
    uVar2 = mm_realloc(*(undefined4 *)(iVar1 + 8),uVar4,1);
    *(undefined4 *)(iVar1 + 8) = uVar2;
    uVar3 = (uint)*(ushort *)(iVar1 + 4);
    if (uVar3 < extraout_a1) {
      memset((void *)(*(int *)(iVar1 + 0xc) + uVar3 * *(ushort *)(iVar1 + 2)),0,
             (uint)*(ushort *)(iVar1 + 2) * (extraout_a1 - uVar3));
      uVar3 = *(ushort *)(iVar1 + 4) + 7 >> 3;
      memset((void *)(*(int *)(iVar1 + 8) + uVar3),0,uVar4 - uVar3);
    }
    goto _L0;
  }
  mempool_deinit_pool();
_L0:
  *(short *)(iVar1 + 4) = (short)extraout_a1;
  return;
}

