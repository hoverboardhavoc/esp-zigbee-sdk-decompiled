/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_attr_report.o -> esp_zb_cli_agent_ep_handler_report
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cli_agent_ep_handler_report(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zb_buf_get_tail_func(0x1a);
  if (*(char *)(iVar1 + 0x12) == '\n') {
    print_attr_update(param_1);
    zb_buf_free_func(param_1);
    uVar2 = 1;
  }
  else if (*(char *)(iVar1 + 0x12) == '\a') {
    iVar1 = get_ctx_by_tsn(*(undefined1 *)(iVar1 + 0x14));
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      cmd_zb_subscribe_unsubscribe_cb(param_1);
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

