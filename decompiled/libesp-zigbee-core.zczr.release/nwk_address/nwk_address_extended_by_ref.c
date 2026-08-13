/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_extended_by_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001090e) */

undefined4 nwk_address_extended_by_ref(uint param_1,undefined1 *param_2)

{
  undefined3 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  iVar3 = core_globals_get();
  iVar4 = *(int *)(iVar3 + 0xc50) + param_1 * 0x12;
  if ((*(byte *)(iVar4 + 0x11) & 4) != 0) {
    param_1 = (uint)*(ushort *)(iVar4 + 0xe);
  }
  iVar4 = check_table_ref(param_1,*(undefined4 *)(iVar3 + 0xc4c),*(undefined2 *)(iVar3 + 0xc54));
  uVar5 = 5;
  if (iVar4 != 0) {
    puVar6 = (undefined4 *)(*(int *)(iVar3 + 0xc50) + param_1 * 0x12);
    if (param_2 != (undefined1 *)0x0) {
      uVar5 = *puVar6;
      uVar1 = *(undefined3 *)(puVar6 + 1);
      uVar2 = puVar6[1];
      *param_2 = (char)*(undefined3 *)puVar6;
      param_2[1] = (char)((uint)uVar5 >> 8);
      param_2[3] = (char)((uint)uVar5 >> 0x18);
      param_2[5] = (char)((uint)uVar2 >> 8);
      param_2[2] = (char)((uint)uVar5 >> 0x10);
      param_2[4] = (char)uVar1;
      param_2[6] = (char)((uint)uVar2 >> 0x10);
      param_2[7] = (char)((uint)uVar2 >> 0x18);
    }
    uVar5 = 0;
  }
  return uVar5;
}

