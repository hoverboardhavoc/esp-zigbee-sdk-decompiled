/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_add_panid_mapping
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_address_add_panid_mapping(undefined2 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar4 = core_globals_get();
  uVar5 = nwk_address_get_panid_ref(param_2);
  if (0xf < uVar5) {
    uVar5 = mempool_alloc_idx(iVar4 + 0xc48,0x10);
    uVar5 = uVar5 & 0xff;
    if (0xf < uVar5) {
      return 0xff;
    }
    uVar1 = *param_2;
    uVar2 = *(undefined2 *)(param_2 + 1);
    uVar3 = param_2[1];
    iVar6 = iVar4 + 0x1000 + uVar5 * 10;
    *(undefined2 *)(iVar6 + -0x458) = *(undefined2 *)param_2;
    *(short *)(iVar6 + -0x456) = (short)((uint)uVar1 >> 0x10);
    *(undefined2 *)(iVar6 + -0x454) = uVar2;
    *(short *)(iVar6 + -0x452) = (short)((uint)uVar3 >> 0x10);
  }
  *(undefined2 *)(iVar4 + uVar5 * 10 + 0xbb0) = param_1;
  return uVar5;
}

