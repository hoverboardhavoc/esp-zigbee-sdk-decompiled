/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_read_variable_attr_size
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
  undefined3 in_register_00002031;
  uint uVar2;
  
  uVar2 = CONCAT31(in_register_00002031,attr_type);
  if (uVar2 == 0x22) {
    return 4;
  }
  if (uVar2 < 0x23) {
    if (uVar2 == 0x1a) {
      return 4;
    }
    if (uVar2 < 0x1b) {
      if (uVar2 == 0xd) {
        return 8;
      }
      if (uVar2 < 0xe) {
        if (uVar2 == 10) {
          return 4;
        }
        if (uVar2 == 0xc) {
          return 8;
        }
      }
      else if (uVar2 == 0xe) {
        return 8;
      }
    }
    else {
      if (uVar2 == 0x1d) {
        return 8;
      }
      if (uVar2 == 0x1e) {
        return 8;
      }
      if (uVar2 == 0x1c) {
        return 8;
      }
    }
  }
  else {
    if (uVar2 == 0x2a) {
      return 4;
    }
    if (uVar2 < 0x2b) {
      if (uVar2 == 0x25) {
        return 8;
      }
      if (uVar2 == 0x26) {
        return 8;
      }
      if (uVar2 == 0x24) {
        return 8;
      }
    }
    else {
      if (uVar2 == 0x2d) {
        return 8;
      }
      if (uVar2 == 0x2e) {
        return 8;
      }
      if (uVar2 == 0x2c) {
        return 8;
      }
    }
  }
  uVar1 = zcl_packet_read_variable_attr_actual_size(payload,offset,attr_type);
  return uVar1;
}

