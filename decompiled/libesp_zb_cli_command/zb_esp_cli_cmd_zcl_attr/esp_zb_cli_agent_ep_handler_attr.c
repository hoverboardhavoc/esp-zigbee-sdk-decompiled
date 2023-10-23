/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_attr.o -> esp_zb_cli_agent_ep_handler_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cli_agent_ep_handler_attr(undefined4 param_1)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  
  iVar3 = zb_buf_get_tail_func(0x1b);
  uVar4 = get_attr_table_row_by_sn(*(undefined1 *)(iVar3 + 0x15));
  if (uVar4 == 0xffffffff) {
    iVar5 = 0;
  }
  else {
    puVar1 = &m_attr_table + uVar4 * 0x3c;
    iVar5 = is_response(iVar3,puVar1);
    if (iVar5 != 0) {
      if (*(char *)(iVar3 + 0x13) == '\v') {
        uVar6 = zb_buf_len_func(param_1);
        if (uVar6 < 2) {
          puVar1 = (undefined1 *)0x0;
        }
        else {
          puVar1 = (undefined1 *)zb_buf_begin_func(param_1);
        }
        uVar6 = zb_buf_len_func(param_1);
        if (1 < uVar6) {
          iVar3 = zb_buf_begin_func(param_1);
          uVar2 = zb_zcl_zcl8_statuses_conversion(*(undefined1 *)(iVar3 + 1));
          *(undefined1 *)(iVar3 + 1) = uVar2;
        }
        uVar7 = esp_log_timestamp();
        esp_log_write(1,&_LC0,&_LC9,uVar7,&_LC0,*puVar1,puVar1[1]);
      }
      else if (*(int *)(&DAT_00011414 + uVar4 * 0x3c) == 0) {
        print_read_attr_response(param_1,puVar1);
      }
      else {
        print_write_attr_response(param_1,puVar1);
      }
      zb_schedule_alarm_cancel(invalidate_row_cb,uVar4 & 0xff,0);
      invalidate_row(uVar4 & 0xff);
      zb_buf_free_func(param_1);
    }
  }
  return iVar5;
}

