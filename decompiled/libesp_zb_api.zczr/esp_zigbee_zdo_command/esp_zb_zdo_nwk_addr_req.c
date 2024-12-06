/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_nwk_addr_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_nwk_addr_req(undefined2 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  
  iVar1 = zb_buf_get_out_func();
  if ((param_1 != (undefined2 *)0x0) && (iVar1 != 0)) {
    puVar2 = (undefined2 *)zb_buf_get_tail_func(0xc);
    *puVar2 = *param_1;
    memcpy(puVar2 + 1,param_1 + 1,8);
    *(undefined1 *)(puVar2 + 5) = *(undefined1 *)(param_1 + 5);
    *(undefined1 *)((int)puVar2 + 0xb) = *(undefined1 *)((int)param_1 + 0xb);
    uVar3 = zb_zdo_nwk_addr_req(iVar1,device_nwk_addr_req_cb);
    zb_schedule_app_alarm(nwk_addr_req_timeout,uVar3,5000000,0);
    esp_zb_zdo_callback_register(uVar3,0,param_2,param_3);
    return;
  }
  return;
}

