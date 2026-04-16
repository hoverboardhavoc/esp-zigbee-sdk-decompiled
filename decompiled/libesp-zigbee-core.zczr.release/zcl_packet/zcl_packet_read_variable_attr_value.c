/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_read_variable_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t zcl_packet_read_variable_attr_value
                   (zcl_packet_payload_t *payload,uint16_t *offset,uint8_t attr_type,void *value)

{
  size_t __size;
  uint16_t uVar1;
  undefined2 extraout_var;
  uint8_t *value_00;
  undefined2 extraout_var_00;
  undefined3 in_register_00002031;
  
  __size = 0xffff;
  if (((payload != (zcl_packet_payload_t *)0x0) && (__size = 0xffff, offset != (uint16_t *)0x0)) &&
     (value != (void *)0x0)) {
    uVar1 = zcl_packet_read_variable_attr_actual_size(payload,*offset,attr_type);
    __size = CONCAT22(extraout_var,uVar1);
    if (((__size - 1 & 0xffff) < 0xfffe) &&
       (value_00 = (uint8_t *)calloc(1,__size), value_00 != (uint8_t *)0x0)) {
      uVar1 = af_read_bytes(payload,offset,uVar1,value_00);
      if (CONCAT22(extraout_var_00,uVar1) == __size) {
        zcl_read_attr_value(value,value_00,CONCAT31(in_register_00002031,attr_type));
      }
      else {
        __size = 0xffff;
      }
      mm_free(value_00);
    }
  }
  return (uint16_t)__size;
}

