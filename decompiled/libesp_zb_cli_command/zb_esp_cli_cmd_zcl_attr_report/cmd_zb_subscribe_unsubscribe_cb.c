/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_attr_report.o -> cmd_zb_subscribe_unsubscribe_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_subscribe_unsubscribe_cb(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  iVar3 = zb_schedule_alarm_cancel(cmd_zb_subscribe_unsubscribe_timeout,0xff,0);
  if (iVar3 != 0) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,&_L0,&_LC7,uVar6,&_L0);
    goto _L0;
  }
  uVar4 = zb_buf_len_func(param_2);
  if (uVar4 < 4) {
    pcVar2 = (char *)zb_buf_begin_func(param_2);
    if (*pcVar2 == '\0') {
      uVar6 = esp_log_timestamp();
      esp_log_write(3,&_L0,&_LC8,uVar6,&_L0);
    }
    else {
      uVar6 = esp_log_timestamp();
      esp_log_write(1,&_L0,&_LC9,uVar6,&_L0,*pcVar2);
    }
    goto _L0;
  }
  iVar3 = zb_buf_len_func(param_2);
  if (iVar3 == 0) {
    pcVar2 = (char *)0x0;
_L0:
    if (pcVar2 != (char *)0x0) {
      bVar1 = false;
      while (pcVar2 != (char *)0x0) {
        if (*pcVar2 == '\0') {
          if (pcVar2[1] == '\0') {
            uVar6 = esp_log_timestamp();
            esp_log_write(3,&_L0,&_LC11,uVar6,&_L0,*(undefined2 *)(pcVar2 + 2));
          }
          else if (pcVar2[1] == '\x01') {
            uVar6 = esp_log_timestamp();
            esp_log_write(3,&_L0,&_LC12,uVar6,&_L0,*(undefined2 *)(pcVar2 + 2));
          }
          else {
            uVar6 = esp_log_timestamp();
            esp_log_write(1,&_L0,&_LC13,uVar6,&_L0,*(undefined2 *)(pcVar2 + 2));
            bVar1 = true;
          }
        }
        else {
          uVar6 = esp_log_timestamp();
          esp_log_write(1,&_L0,&_LC14,uVar6,&_L0,*(undefined2 *)(pcVar2 + 2),*pcVar2);
          bVar1 = true;
        }
        iVar3 = zb_buf_len_func(param_2);
        if (iVar3 == 0) {
          pcVar2 = (char *)0x0;
        }
        else {
          pcVar2 = (char *)zb_buf_begin_func(param_2);
        }
        if (pcVar2 == (char *)0x0) break;
        iVar3 = zb_zcl_zcl8_statuses_conversion(*pcVar2);
        *pcVar2 = (char)iVar3;
        if (iVar3 == 0) {
          uVar4 = 1;
        }
        else if (iVar3 == 0x80) {
          uVar4 = 1;
        }
        else {
          zb_buf_len_func(param_2);
          uVar4 = 4;
        }
        uVar5 = zb_buf_len_func(param_2);
        if (uVar5 < uVar4) break;
        zb_buf_cut_left_func(param_2,uVar4);
      }
      if (bVar1) {
        uVar6 = esp_log_timestamp();
        esp_log_write(1,&_L0,&_LC15,uVar6,&_L0);
      }
      else {
        uVar6 = esp_log_timestamp();
        esp_log_write(3,&_L0,&_LC8,uVar6,&_L0);
      }
      goto _L0;
    }
  }
  else {
    pcVar2 = (char *)zb_buf_begin_func(param_2);
    if (pcVar2 != (char *)0x0) {
      iVar3 = zb_zcl_zcl8_statuses_conversion(*pcVar2);
      *pcVar2 = (char)iVar3;
      if (iVar3 == 0) {
        uVar4 = 1;
      }
      else if (iVar3 == 0x80) {
        uVar4 = 1;
      }
      else {
        zb_buf_len_func(param_2);
        uVar4 = 4;
      }
      uVar5 = zb_buf_len_func(param_2);
      if (uVar4 <= uVar5) {
        zb_buf_cut_left_func(param_2,uVar4);
        goto _L0;
      }
    }
  }
  uVar6 = esp_log_timestamp();
  esp_log_write(1,&_L0,&_LC10,uVar6,&_L0);
_L0:
  invalidate_ctx(param_1);
  zb_buf_free_func(param_2);
  return;
}

