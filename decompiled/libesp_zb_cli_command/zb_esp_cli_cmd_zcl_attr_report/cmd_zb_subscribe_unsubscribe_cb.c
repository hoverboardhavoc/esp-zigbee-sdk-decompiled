/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
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
  undefined4 uVar5;
  uint uVar6;
  
  iVar3 = zb_schedule_alarm_cancel(cmd_zb_subscribe_unsubscribe_timeout,0xff,0);
  if (iVar3 != 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,&_L0,&_L0,uVar5,&_L0);
    goto _L0;
  }
  uVar4 = zb_buf_len_func(param_2);
  if (uVar4 < 4) {
    pcVar2 = (char *)zb_buf_begin_func(param_2);
    if (*pcVar2 == '\0') {
      uVar5 = esp_log_timestamp();
      esp_log_write(3,&_L0,&_LC8,uVar5,&_L0);
    }
    else {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,&_L0,&_LC9,uVar5,&_L0,*pcVar2);
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
            uVar5 = esp_log_timestamp();
            esp_log_write(3,&_L0,&_LC11,uVar5,&_L0,*(undefined2 *)(pcVar2 + 2));
          }
          else if (pcVar2[1] == '\x01') {
            uVar5 = esp_log_timestamp();
            esp_log_write(3,&_L0,&_LC12,uVar5,&_L0,*(undefined2 *)(pcVar2 + 2));
          }
          else {
            uVar5 = esp_log_timestamp();
            esp_log_write(1,&_L0,&_LC13,uVar5,&_L0,*(undefined2 *)(pcVar2 + 2));
            bVar1 = true;
          }
        }
        else {
          uVar5 = esp_log_timestamp();
          esp_log_write(1,&_L0,&_LC14,uVar5,&_L0,*(undefined2 *)(pcVar2 + 2),*pcVar2);
          bVar1 = true;
        }
        iVar3 = zb_buf_len_func(param_2);
        if (iVar3 == 0) {
          pcVar2 = (char *)0x0;
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
            uVar6 = zb_buf_len_func(param_2);
            if (uVar6 < uVar4) break;
            zb_buf_cut_left_func(param_2,uVar4);
          }
        }
      }
      if (bVar1) {
        uVar5 = esp_log_timestamp();
        esp_log_write(1,&_L0,&_LC15,uVar5,&_L0);
      }
      else {
        uVar5 = esp_log_timestamp();
        esp_log_write(3,&_L0,&_LC8,uVar5,&_L0);
      }
      goto _L0;
    }
  }
  else {
    pcVar2 = (char *)zb_buf_begin_func(param_2);
    if (pcVar2 == (char *)0x0) goto _L0;
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
    uVar6 = zb_buf_len_func(param_2);
    if (uVar4 <= uVar6) {
      zb_buf_cut_left_func(param_2,uVar4);
      goto _L0;
    }
  }
  uVar5 = esp_log_timestamp();
  esp_log_write(1,&_L0,&_LC10,uVar5,&_L0);
_L0:
  invalidate_ctx(param_1);
  zb_buf_free_func(param_2);
  return;
}

