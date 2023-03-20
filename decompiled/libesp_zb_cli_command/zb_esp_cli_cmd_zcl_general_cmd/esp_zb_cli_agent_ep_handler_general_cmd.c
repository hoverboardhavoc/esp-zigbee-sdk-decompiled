/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_general_cmd.o -> esp_zb_cli_agent_ep_handler_general_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_cli_agent_ep_handler_general_cmd(undefined4 param_1)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  
  iVar3 = zb_buf_get_tail_func(0x1a);
  uVar4 = get_cmd_table_row_by_sn(*(undefined1 *)(iVar3 + 0x14));
  if (uVar4 == 0xffffffff) {
    iVar5 = 0;
  }
  else {
    iVar5 = is_response(iVar3,&m_cmd_data + uVar4 * 0x2e);
    if (iVar5 != 0) {
      if (*(char *)(iVar3 + 0x12) == '\v') {
        uVar7 = zb_buf_len_func(param_1);
        if (uVar7 < 2) {
          puVar1 = (undefined1 *)0x0;
        }
        else {
          puVar1 = (undefined1 *)zb_buf_begin_func(param_1);
        }
        uVar7 = zb_buf_len_func(param_1);
        if (1 < uVar7) {
          iVar3 = zb_buf_begin_func(param_1);
          uVar2 = zb_zcl_zcl8_statuses_conversion(*(undefined1 *)(iVar3 + 1));
          *(undefined1 *)(iVar3 + 1) = uVar2;
        }
        if (puVar1[1] == '\0') {
          uVar6 = esp_log_timestamp();
          esp_log_write(3,&_L0,&_LC21,uVar6,&_L0,*puVar1,puVar1[1]);
          uVar6 = esp_log_timestamp();
          esp_log_write(3,&_L0,&_LC2,uVar6,&_L0);
        }
        else {
          uVar6 = esp_log_timestamp();
          esp_log_write(1,&_L0,&_L0,uVar6,&_L0,*puVar1,puVar1[1]);
          uVar6 = esp_log_timestamp();
          esp_log_write(1,&_L0,&_LC20,uVar6,&_L0);
        }
      }
      else {
        uVar6 = esp_log_timestamp();
        esp_log_write(1,&_L0,&_LC22,uVar6,&_L0);
      }
      if (((&DAT_00010da4)[uVar4 * 0x2e] == '\0') &&
         (iVar3 = zb_schedule_alarm_cancel(invalidate_row_cb,uVar4 & 0xff,0), iVar3 != 0)) {
        uVar6 = esp_log_timestamp();
        esp_log_write(1,&_L0,&_LC23,uVar6,&_L0,iVar3);
      }
      invalidate_row(uVar4 & 0xff);
      zb_buf_free_func(param_1);
    }
  }
  return iVar5;
}

