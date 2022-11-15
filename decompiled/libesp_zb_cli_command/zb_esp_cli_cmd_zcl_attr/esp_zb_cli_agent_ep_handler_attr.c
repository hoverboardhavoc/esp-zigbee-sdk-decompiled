/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_attr.o -> esp_zb_cli_agent_ep_handler_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cli_agent_ep_handler_attr(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  
  iVar2 = zb_buf_get_tail_func(0x1a);
  uVar3 = get_attr_table_row_by_sn(*(undefined1 *)(iVar2 + 0x14));
  if (uVar3 == 0xffffffff) {
    iVar4 = 0;
  }
  else {
    puVar7 = &m_attr_table + uVar3 * 0x3c;
    iVar4 = is_response(iVar2,puVar7);
    if (iVar4 != 0) {
      if (*(char *)(iVar2 + 0x12) == '\v') {
        uVar5 = zb_buf_len_func(param_1);
        if (uVar5 < 2) {
          puVar7 = (undefined1 *)0x0;
        }
        else {
          puVar7 = (undefined1 *)zb_buf_begin_func(param_1);
        }
        uVar5 = zb_buf_len_func(param_1);
        if (1 < uVar5) {
          iVar2 = zb_buf_begin_func(param_1);
          uVar1 = zb_zcl_zcl8_statuses_conversion(*(undefined1 *)(iVar2 + 1));
          *(undefined1 *)(iVar2 + 1) = uVar1;
        }
        uVar6 = esp_log_timestamp();
        esp_log_write(1,&_L0,&_LC9,uVar6,&_L0,*puVar7,puVar7[1]);
      }
      else if (*(int *)(&DAT_00011450 + uVar3 * 0x3c) == 0) {
        print_read_attr_response(param_1,puVar7);
      }
      else {
        print_write_attr_response(param_1,puVar7);
      }
      zb_schedule_alarm_cancel(invalidate_row_cb,uVar3 & 0xff,0);
      invalidate_row(uVar3 & 0xff);
      zb_buf_free_func(param_1);
    }
  }
  return iVar4;
}

