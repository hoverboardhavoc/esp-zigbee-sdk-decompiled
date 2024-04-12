/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_ping.o -> find_request_by_short
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * find_request_by_short(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  do {
    if (9 < iVar1) {
      return (undefined1 *)0x0;
    }
    if ((&m_ping_request_table)[iVar1 * 0x20] != '\0') {
      if ((&DAT_00011079)[iVar1 * 0x20] == '\x02') {
        if ((*(uint *)(&m_ping_request_table + iVar1 * 0x20) >> 8 & 0xffff) == param_1) {
          return &m_ping_request_table + iVar1 * 0x20;
        }
      }
      else {
        uVar2 = zb_address_short_by_ieee(&DAT_00011071 + iVar1 * 0x20);
        if (uVar2 == param_1) {
          return &m_ping_request_table + iVar1 * 0x20;
        }
      }
    }
    iVar1 = iVar1 + 1;
  } while( true );
}

