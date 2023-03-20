/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_mgmt_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_mgmt_leave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_LC38,uVar4,&_LC3);
    iVar2 = 0;
  }
  else {
    zb_buf_get_tail_func(0xb);
    iVar2 = cmd_zb_mgmt_leave_parse(param_1,param_2);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = get_free_ctx();
      if (iVar2 == 0) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,&_LC3,&_LC40,uVar4,&_LC3);
      }
      else {
        iVar3 = zdo_mgmt_leave_req(iVar1,cmd_zb_mgmt_leave_cb);
        *(char *)(iVar2 + 4) = (char)iVar3;
        if (iVar3 != 0xff) {
          iVar1 = zb_schedule_app_alarm(cmd_zb_mgmt_leave_timeout_cb,0x14a);
          if (iVar1 == 0) {
            return;
          }
          uVar4 = esp_log_timestamp();
          esp_log_write(1,&_LC3,&_LC45,uVar4,&_LC3);
          invalidate_ctx(iVar2);
          return;
        }
        uVar4 = esp_log_timestamp(0xff);
        esp_log_write(1,&_LC3,&_LC44,uVar4,&_LC3);
      }
    }
  }
  if (iVar1 != 0) {
    zb_buf_free_func(iVar1);
  }
  if (iVar2 != 0) {
    invalidate_ctx(iVar2);
  }
  return;
}

