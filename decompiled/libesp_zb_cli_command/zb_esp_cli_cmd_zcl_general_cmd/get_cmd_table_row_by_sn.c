/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_general_cmd.o -> get_cmd_table_row_by_sn
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int get_cmd_table_row_by_sn(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (0x13 < iVar1) {
      return -1;
    }
    if (((&m_cmd_data)[iVar1 * 0x2e] != '\0') && ((byte)(&DAT_00010d7d)[iVar1 * 0x2e] == param_1))
    break;
    iVar1 = iVar1 + 1;
  }
  return (int)(char)iVar1;
}

