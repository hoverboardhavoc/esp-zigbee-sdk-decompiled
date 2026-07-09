/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_get_extpanid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_address_get_extpanid(int param_1,undefined1 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = core_globals_get();
  iVar7 = check_table_ref(param_1,iVar6 + 0xc48,0x10);
  if (iVar7 != 0) {
    iVar6 = iVar6 + 0x1000 + param_1 * 10;
    puVar1 = (undefined4 *)(iVar6 + -0x458);
    uVar4 = *puVar1;
    puVar2 = (undefined4 *)(iVar6 + -0x454);
    uVar3 = *(undefined2 *)puVar2;
    uVar5 = *puVar2;
    *param_2 = (char)*(undefined2 *)puVar1;
    param_2[1] = (char)((uint)uVar4 >> 8);
    param_2[2] = (char)((uint)uVar4 >> 0x10);
    param_2[3] = (char)((uint)uVar4 >> 0x18);
    param_2[4] = (char)uVar3;
    param_2[5] = (char)((uint)uVar5 >> 8);
    param_2[6] = (char)((uint)uVar5 >> 0x10);
    param_2[7] = (char)((uint)uVar5 >> 0x18);
  }
  return;
}

