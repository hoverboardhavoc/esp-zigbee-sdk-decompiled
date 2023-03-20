/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
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
    if (((&m_attr_table)[iVar1 * 0x3c] != '\0') && ((byte)(&DAT_00011415)[iVar1 * 0x3c] == param_1))
    break;
    iVar1 = iVar1 + 1;
  }
  return (int)(char)iVar1;
}

