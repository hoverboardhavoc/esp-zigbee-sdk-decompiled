/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_attr.o -> get_attr_table_row_by_sn
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int get_attr_table_row_by_sn(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (0x13 < iVar1) {
      return -1;
    }
    if (((&m_attr_table)[iVar1 * 0x3c] != '\0') && ((byte)(&DAT_0001144d)[iVar1 * 0x3c] == param_1))
    break;
    iVar1 = iVar1 + 1;
  }
  return (int)(char)iVar1;
}

