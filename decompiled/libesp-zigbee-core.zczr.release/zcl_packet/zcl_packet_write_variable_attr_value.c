/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_write_variable_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_packet_write_variable_attr_value
               (zcl_packet_payload_t *payload,uint16_t offset,uint8_t attr_type,void *value)

{
  int iVar1;
  uint uVar2;
  undefined2 in_register_0000202e;
  undefined3 in_register_00002031;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 local_30;
  uint8_t buf [16];
  
  uVar3 = CONCAT31(in_register_00002031,attr_type);
  puVar4 = &local_30;
  local_30 = 0;
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  buf[9] = '\0';
  buf[10] = '\0';
  buf[0xb] = '\0';
  iVar1 = zcl_attr_type_is_composite(uVar3);
  if (iVar1 == 0) {
    uVar2 = zcl_get_attr_value_size(uVar3,0);
    if (0x10 < uVar2) {
      __assert_func(0,0,0,0);
    }
    zcl_write_attr_value(&local_30,value,uVar3);
  }
  else {
    uVar2 = zcl_get_attr_value_size(uVar3,value);
    puVar4 = (undefined4 *)value;
  }
  zmsg_write_bytes(payload,CONCAT22(in_register_0000202e,offset),uVar2,puVar4);
  return;
}

