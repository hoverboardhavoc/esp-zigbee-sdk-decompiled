/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_set_extended_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_set_extended_panid(ezb_extpanid_t *extpanid)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = core_globals_get();
  puVar1 = (undefined4 *)((int)&extpanid->field_0 + 4);
  uVar2 = *(undefined2 *)puVar1;
  uVar3 = *(undefined4 *)&extpanid->field_0;
  uVar4 = *puVar1;
  *(char *)(iVar5 + 0x9ef) = (char)*(undefined2 *)&extpanid->field_0;
  *(char *)(iVar5 + 0x9f0) = (char)((uint)uVar3 >> 8);
  *(char *)(iVar5 + 0x9f2) = (char)((uint)uVar3 >> 0x18);
  *(char *)(iVar5 + 0x9f4) = (char)((uint)uVar4 >> 8);
  *(char *)(iVar5 + 0x9f1) = (char)((uint)uVar3 >> 0x10);
  *(char *)(iVar5 + 0x9f3) = (char)uVar2;
  *(char *)(iVar5 + 0x9f5) = (char)((uint)uVar4 >> 0x10);
  *(char *)(iVar5 + 0x9f6) = (char)((uint)uVar4 >> 0x18);
  return;
}

