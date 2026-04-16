/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_api.o -> ezb_aps_set_use_extended_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_aps_set_use_extended_panid(ezb_extpanid_t *extpanid)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = core_globals_get();
  uVar2 = *(undefined4 *)&extpanid->field_0;
  puVar1 = (undefined4 *)((int)&extpanid->field_0 + 4);
  uVar3 = *(undefined2 *)puVar1;
  uVar4 = *puVar1;
  *(char *)(iVar5 + 0xc) = (char)*(undefined2 *)&extpanid->field_0;
  *(char *)(iVar5 + 0xd) = (char)((uint)uVar2 >> 8);
  *(char *)(iVar5 + 0xe) = (char)((uint)uVar2 >> 0x10);
  *(char *)(iVar5 + 0xf) = (char)((uint)uVar2 >> 0x18);
  *(char *)(iVar5 + 0x10) = (char)uVar3;
  *(char *)(iVar5 + 0x11) = (char)((uint)uVar4 >> 8);
  *(char *)(iVar5 + 0x12) = (char)((uint)uVar4 >> 0x10);
  *(char *)(iVar5 + 0x13) = (char)((uint)uVar4 >> 0x18);
  return;
}

