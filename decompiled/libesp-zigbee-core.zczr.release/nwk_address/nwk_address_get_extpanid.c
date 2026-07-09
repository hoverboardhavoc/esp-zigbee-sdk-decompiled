/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_get_extpanid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_address_get_extpanid(int param_1,undefined1 *param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = core_globals_get();
  iVar6 = check_table_ref(param_1,iVar5 + 0xc48,0x10);
  if (iVar6 != 0) {
    iVar5 = iVar5 + 0x1000 + param_1 * 10;
    uVar1 = *(undefined2 *)(iVar5 + -0x458);
    uVar2 = *(undefined2 *)(iVar5 + -0x456);
    uVar3 = *(undefined2 *)(iVar5 + -0x454);
    uVar4 = *(undefined2 *)(iVar5 + -0x452);
    *param_2 = (char)uVar1;
    param_2[2] = (char)uVar2;
    param_2[4] = (char)uVar3;
    param_2[6] = (char)uVar4;
    param_2[1] = (char)((ushort)uVar1 >> 8);
    param_2[3] = (char)((ushort)uVar2 >> 8);
    param_2[5] = (char)((ushort)uVar3 >> 8);
    param_2[7] = (char)((ushort)uVar4 >> 8);
  }
  return;
}

