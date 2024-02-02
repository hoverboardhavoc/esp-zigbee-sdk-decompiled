/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_simple_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_simple_desc(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined2 uStack_12;
  
  if (param_1 == 2) {
    iVar2 = zb_buf_get_out_func();
    if (iVar2 == 0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,&_LC0,&_LC81,uVar1,&_LC0);
    }
    else {
      puVar3 = (undefined1 *)zb_buf_initial_alloc_func(3);
      iVar4 = parse_hex_u16(*param_2,&uStack_12);
      if (iVar4 == 0) {
        uVar1 = esp_log_timestamp();
        esp_log_write(1,&_LC0,&_LC82,uVar1,&_LC0);
      }
      else {
        *puVar3 = (char)uStack_12;
        puVar3[1] = (char)((ushort)uStack_12 >> 8);
        uVar1 = esp_log_timestamp();
        esp_log_write(3,&_LC0,&_LC83,uVar1,&_LC0,uStack_12);
        iVar4 = sscan_uint8(param_2[1],puVar3 + 2);
        if (iVar4 == 0) {
          uVar1 = esp_log_timestamp();
          esp_log_write(1,&_LC0,&_LC84,uVar1,&_LC0);
        }
        else {
          uVar1 = esp_log_timestamp();
          esp_log_write(3,&_LC0,&_LC85,uVar1,&_LC0,puVar3[2]);
          iVar4 = get_free_ctx();
          if (iVar4 == 0) {
            uVar1 = esp_log_timestamp();
            esp_log_write(1,&_LC0,&_LC33,uVar1,&_LC0);
          }
          else {
            iVar5 = zb_zdo_simple_desc_req(iVar2,cmd_zb_simple_desc_req_cb);
            *(char *)(iVar4 + 4) = (char)iVar5;
            if (iVar5 != 0xff) {
              return;
            }
            uVar1 = esp_log_timestamp();
            esp_log_write(1,&_LC0,&_LC34,uVar1,&_LC0);
          }
        }
      }
      zb_buf_free_func(iVar2);
    }
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,&_LC0,&_LC80,uVar1,&_LC0);
  }
  return;
}

