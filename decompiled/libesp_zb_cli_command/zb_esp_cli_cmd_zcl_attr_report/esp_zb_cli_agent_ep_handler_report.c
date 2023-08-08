/*
 * Last changed at upstream commit d04ab25a7353bae74042267d24c5fef5f02d0726
 * https://github.com/espressif/esp-zigbee-sdk/commit/d04ab25a7353bae74042267d24c5fef5f02d0726
 * Upstream date: 2023-08-08 16:02:31 +0800
 * Upstream subject: esp-zigbee-sdk: add touchlink example
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
  
  iVar1 = zb_buf_get_tail_func(0x1b);
  if (*(char *)(iVar1 + 0x13) == '\n') {
    print_attr_update(param_1);
    zb_buf_free_func(param_1);
    uVar2 = 1;
  }
  else if (*(char *)(iVar1 + 0x13) == '\a') {
    iVar1 = get_ctx_by_tsn(*(undefined1 *)(iVar1 + 0x15));
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

