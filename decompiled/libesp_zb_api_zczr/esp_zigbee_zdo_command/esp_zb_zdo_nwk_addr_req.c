/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_nwk_addr_req
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

