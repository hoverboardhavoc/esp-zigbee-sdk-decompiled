/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_mgmt_lqi
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_mgmt_lqi(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  if (param_1 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_L0,uVar5,&_LC3);
    return;
  }
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_L0,uVar5,&_LC3);
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined1 *)zb_buf_get_tail_func(4);
    iVar3 = parse_address(*param_2,puVar2 + 2,2);
    if (iVar3 == 0) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,&_LC3,&_LC103,uVar5,&_LC3);
      puVar4 = (undefined4 *)0x0;
    }
    else {
      if (param_1 == 2) {
        iVar3 = sscan_uint8(param_2[1],puVar2);
        if (iVar3 == 0) {
          uVar5 = esp_log_timestamp();
          esp_log_write(1,&_LC3,&_LC104,uVar5,&_LC3);
          puVar4 = (undefined4 *)0x0;
          goto _L0;
        }
      }
      else {
        *puVar2 = 0;
      }
      puVar4 = (undefined4 *)get_free_ctx();
      if (puVar4 == (undefined4 *)0x0) {
        uVar5 = esp_log_timestamp();
        esp_log_write(1,&_LC3,&_LC36,uVar5,&_LC3);
      }
      else {
        *puVar4 = zdo_mgmt_lqi_cb;
        iVar3 = zb_zdo_mgmt_lqi_req(iVar1,zdo_request_cb);
        *(char *)(puVar4 + 1) = (char)iVar3;
        if (iVar3 != 0xff) {
          iVar1 = zb_schedule_app_alarm(ctx_timeout_cb,0x14a,0);
          if (iVar1 == 0) {
            return;
          }
          uVar5 = esp_log_timestamp();
          esp_log_write(1,&_LC3,&_LC60,uVar5,&_LC3);
          invalidate_ctx(puVar4);
          return;
        }
        uVar5 = esp_log_timestamp(0xff);
        esp_log_write(1,&_LC3,&_LC40,uVar5,&_LC3);
      }
    }
  }
_L0:
  if (iVar1 != 0) {
    zb_buf_free_func(iVar1);
  }
  if (puVar4 != (undefined4 *)0x0) {
    invalidate_ctx(puVar4);
  }
  return;
}

