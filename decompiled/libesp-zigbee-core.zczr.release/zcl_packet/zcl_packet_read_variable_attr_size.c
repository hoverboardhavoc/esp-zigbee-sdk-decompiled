/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_read_variable_attr_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t zcl_packet_read_variable_attr_size
                   (zcl_packet_payload_t *payload,uint16_t offset,uint8_t attr_type)

{
  uint16_t uVar1;
  short sVar2;
  int iVar3;
  undefined3 in_register_00002031;
  uint uVar4;
  uint uVar5;
  uint16_t uStack_22;
  uint auStack_20 [5];
  
  uVar4 = CONCAT31(in_register_00002031,attr_type);
  if (uVar4 < 0x2f) {
    if (uVar4 < 0x1a) {
      if (uVar4 == 10) {
        return 4;
      }
      if ((uVar4 - 0xc & 0xff) < 3) {
        return 8;
      }
    }
    else {
      uVar5 = 1 << (uVar4 - 0x1a & 0x1f);
      if ((uVar5 & 0x1c1c1c) != 0) {
        return 8;
      }
      if ((uVar5 & 0x10101) != 0) {
        return 4;
      }
    }
  }
  auStack_20[0] = 0;
  auStack_20[1] = 0;
  auStack_20[2] = 0;
  auStack_20[3] = 0;
  uStack_22 = offset;
  iVar3 = zcl_attr_type_is_composite(uVar4);
  if (iVar3 == 0) {
    uVar1 = zcl_get_attr_value_size(uVar4,0);
  }
  else if ((uVar4 - 0x41 & 0xff) < 2) {
    af_read_bytes(payload,&uStack_22,1,(uint8_t *)auStack_20);
    uVar1 = (byte)auStack_20[0] + 1;
  }
  else {
    if ((uVar4 - 0x43 & 0xff) < 2) {
      af_read_bytes(payload,&uStack_22,2,(uint8_t *)auStack_20);
      sVar2 = (short)auStack_20[0];
    }
    else {
      if (uVar4 == 0x49) {
        af_read_bytes(payload,&uStack_22,2,(uint8_t *)auStack_20);
        return ((short)auStack_20[0] + 1) * 2;
      }
      if (uVar4 != 0x4a) {
        return 0;
      }
      af_read_bytes(payload,&uStack_22,2,(uint8_t *)auStack_20);
      sVar2 = (short)((auStack_20[0] & 0xffff) << 2);
    }
    uVar1 = sVar2 + 2;
  }
  return uVar1;
}

