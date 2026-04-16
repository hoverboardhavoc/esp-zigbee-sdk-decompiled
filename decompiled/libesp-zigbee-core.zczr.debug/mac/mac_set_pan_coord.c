/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_set_pan_coord
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_set_pan_coord(mac_device *dev,_Bool is_pan_coord)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined3 uVar3;
  undefined4 uVar4;
  undefined3 in_register_0000202d;
  
  if (CONCAT31(in_register_0000202d,is_pan_coord) != 0) {
    (dev->pib).coord_shortaddr = (dev->pib).short_address;
    uVar2 = *(undefined4 *)&(dev->pib).extended_address.field_0;
    puVar1 = (undefined4 *)((int)&(dev->pib).extended_address.field_0 + 4);
    uVar3 = *(undefined3 *)puVar1;
    uVar4 = *puVar1;
    (dev->pib).coord_extaddr.field_0.u8[0] =
         (uint8_t)*(undefined3 *)&(dev->pib).extended_address.field_0;
    (dev->pib).coord_extaddr.field_0.u8[1] = (uint8_t)((uint)uVar2 >> 8);
    (dev->pib).coord_extaddr.field_0.u8[2] = (uint8_t)((uint)uVar2 >> 0x10);
    (dev->pib).coord_extaddr.field_0.u8[3] = (uint8_t)((uint)uVar2 >> 0x18);
    (dev->pib).coord_extaddr.field_0.u8[4] = (uint8_t)uVar3;
    (dev->pib).coord_extaddr.field_0.u8[5] = (uint8_t)((uint)uVar4 >> 8);
    (dev->pib).coord_extaddr.field_0.u8[6] = (uint8_t)((uint)uVar4 >> 0x10);
    (dev->pib).coord_extaddr.field_0.u8[7] = (uint8_t)((uint)uVar4 >> 0x18);
    return;
  }
  (dev->pib).coord_shortaddr = 0xffff;
  (dev->pib).coord_extaddr.field_0.u8[0] = '\0';
  (dev->pib).coord_extaddr.field_0.u8[1] = '\0';
  (dev->pib).coord_extaddr.field_0.u8[2] = '\0';
  (dev->pib).coord_extaddr.field_0.u8[3] = '\0';
  (dev->pib).coord_extaddr.field_0.u8[4] = '\0';
  (dev->pib).coord_extaddr.field_0.u8[5] = '\0';
  (dev->pib).coord_extaddr.field_0.u8[6] = '\0';
  (dev->pib).coord_extaddr.field_0.u8[7] = '\0';
  return;
}

