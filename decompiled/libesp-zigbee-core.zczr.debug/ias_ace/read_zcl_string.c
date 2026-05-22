/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> read_zcl_string
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
read_zcl_string(zcl_packet_payload_t *payload,uint16_t *offset,uint8_t *string,uint8_t max_length)

{
  undefined3 in_register_00002035;
  
  if (((payload == (zcl_packet_payload_t *)0x0) || (offset == (uint16_t *)0x0)) ||
     (string == (uint8_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0xc5,
                  "read_zcl_string","payload && offset && string");
  }
  else {
    af_read_le8(payload,offset,string);
    if ((uint)*string < CONCAT31(in_register_00002035,max_length)) {
      af_read_bytes(payload,offset,(ushort)*string,string + 1);
      return '\0';
    }
  }
  return 0x87;
}

