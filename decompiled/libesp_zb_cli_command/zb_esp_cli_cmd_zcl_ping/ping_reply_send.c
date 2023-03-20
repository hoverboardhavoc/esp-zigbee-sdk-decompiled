/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_ping.o -> ping_reply_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ping_reply_send(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  uVar1 = zb_cli_get_endpoint();
  iVar2 = zb_buf_get_out_func();
  if (iVar2 == 0) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,&_LC0,&_LC10,uVar1,&_LC0);
    ping_release_reply(param_1);
  }
  else {
    puVar3 = (undefined1 *)zb_buf_reuse_func();
    *puVar3 = 0x11;
    puVar3[1] = *(undefined1 *)(param_1 + 4);
    puVar3[2] = 1;
    memset(puVar3 + 3,0xcd,(uint)*(byte *)(param_1 + 5));
    zb_zcl_finish_and_send_packet_no_ack
              (iVar2,puVar3 + 3 + *(byte *)(param_1 + 5),param_1 + 2,2,uVar1,uVar1,0x104,0xbeef);
    ping_release_reply(param_1);
  }
  return;
}

