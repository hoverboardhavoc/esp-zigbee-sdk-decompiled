/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_api.o -> ezb_aps_get_use_extended_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_aps_get_use_extended_panid(ezb_extpanid_t *extpanid)

{
  undefined4 uVar1;
  undefined3 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = core_globals_get();
  uVar1 = *(undefined4 *)(iVar4 + 0xc);
  uVar2 = *(undefined3 *)(iVar4 + 0x10);
  uVar3 = *(undefined4 *)(iVar4 + 0x10);
  (extpanid->field_0).u8[0] = (uint8_t)*(undefined3 *)(iVar4 + 0xc);
  (extpanid->field_0).u8[1] = (uint8_t)((uint)uVar1 >> 8);
  (extpanid->field_0).u8[3] = (uint8_t)((uint)uVar1 >> 0x18);
  (extpanid->field_0).u8[5] = (uint8_t)((uint)uVar3 >> 8);
  (extpanid->field_0).u8[2] = (uint8_t)((uint)uVar1 >> 0x10);
  (extpanid->field_0).u8[4] = (uint8_t)uVar2;
  (extpanid->field_0).u8[6] = (uint8_t)((uint)uVar3 >> 0x10);
  (extpanid->field_0).u8[7] = (uint8_t)((uint)uVar3 >> 0x18);
  return;
}

