/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_mgmt_bind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_mgmt_bind(uint param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  iVar1 = get_free_ctx();
  if (iVar1 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_LC40,uVar4,&_LC3);
  }
  else if (param_1 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_LC96,uVar4,&_LC3);
  }
  else {
    iVar2 = parse_address(*param_2,iVar1 + 10,2);
    if (iVar2 == 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,&_LC3,&_LC47,uVar4,&_LC3);
    }
    else {
      if (param_1 < 2) {
        *(undefined1 *)(iVar1 + 8) = 0;
        uVar6 = 1;
      }
      else {
        iVar2 = sscan_uint8(param_2[1],iVar1 + 8);
        if (iVar2 == 0) {
          uVar4 = esp_log_timestamp();
          esp_log_write(1,&_LC3,&_LC97,uVar4,&_LC3);
          goto _L0;
        }
        uVar6 = 2;
      }
      if (uVar6 < param_1) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,&_LC3,&_LC98,uVar4,&_LC3);
      }
      else {
        iVar2 = zb_buf_get_out_func();
        if (iVar2 == 0) {
          uVar4 = esp_log_timestamp();
          esp_log_write(1,&_LC3,&_LC38,uVar4,&_LC3);
        }
        else {
          puVar3 = (undefined1 *)zb_buf_get_tail_func(4);
          *puVar3 = 0;
          puVar3[1] = 0;
          puVar3[2] = 0;
          puVar3[3] = 0;
          *puVar3 = *(undefined1 *)(iVar1 + 8);
          *(undefined2 *)(puVar3 + 2) = *(undefined2 *)(iVar1 + 10);
          uVar4 = esp_log_timestamp();
          esp_log_write(3,&_LC3,&_LC99,uVar4,&_LC3,*puVar3,*(undefined2 *)(puVar3 + 2));
          iVar5 = zb_zdo_mgmt_bind_req(iVar2,cmd_zb_mgmt_bind_cb);
          *(char *)(iVar1 + 4) = (char)iVar5;
          if (iVar5 != 0xff) {
            return;
          }
          uVar4 = esp_log_timestamp();
          esp_log_write(1,&_LC3,&_LC44,uVar4,&_LC3);
        }
        if (iVar2 != 0) {
          zb_buf_free_func(iVar2);
        }
      }
    }
  }
_L0:
  if (iVar1 != 0) {
    invalidate_ctx(iVar1);
  }
  return;
}

