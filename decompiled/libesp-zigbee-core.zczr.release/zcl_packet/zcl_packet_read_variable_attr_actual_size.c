/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_read_variable_attr_actual_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t zcl_packet_read_variable_attr_actual_size
                   (zcl_packet_payload_t *payload,uint16_t offset,uint8_t attr_type)

{
  uint16_t uVar1;
  short sVar2;
  int iVar3;
  undefined3 in_register_00002031;
  int iVar4;
  uint16_t uStack_22;
  uint uStack_20;
  uint8_t buf [16];
  
  iVar4 = CONCAT31(in_register_00002031,attr_type);
  uStack_20 = 0;
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
  uStack_22 = offset;
  iVar3 = zcl_attr_type_is_composite(iVar4);
  if (iVar3 == 0) {
    uVar1 = zcl_get_attr_value_size(iVar4,0);
  }
  else if ((iVar4 - 0x41U & 0xff) < 2) {
    af_read_bytes(payload,&uStack_22,1,(uint8_t *)&uStack_20);
    uVar1 = (byte)uStack_20 + 1;
  }
  else {
    if ((iVar4 - 0x43U & 0xff) < 2) {
      af_read_bytes(payload,&uStack_22,2,(uint8_t *)&uStack_20);
      sVar2 = (short)uStack_20;
    }
    else {
      if (iVar4 == 0x49) {
        af_read_bytes(payload,&uStack_22,2,(uint8_t *)&uStack_20);
        return ((short)uStack_20 + 1) * 2;
      }
      if (iVar4 != 0x4a) {
        return 0;
      }
      af_read_bytes(payload,&uStack_22,2,(uint8_t *)&uStack_20);
      sVar2 = (short)((uStack_20 & 0xffff) << 2);
    }
    uVar1 = sVar2 + 2;
  }
  return uVar1;
}

