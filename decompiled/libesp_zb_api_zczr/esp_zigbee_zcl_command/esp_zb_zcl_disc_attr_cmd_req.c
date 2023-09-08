/*
 * Last changed at upstream commit d50acd5408f73d4459b46a949332bb6e32f97543
 * https://github.com/espressif/esp-zigbee-sdk/commit/d50acd5408f73d4459b46a949332bb6e32f97543
 * Upstream date: 2023-09-08 17:20:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.4(89250ad3)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_disc_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_disc_attr_cmd_req(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined1 uVar5;
  
  uVar2 = zb_buf_get_out_func();
  puVar3 = (undefined1 *)zb_buf_reuse_func();
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = 8;
  }
  *puVar3 = uVar5;
  pcVar4 = (char *)zb_zcl_get_ctx();
  cVar1 = *pcVar4;
  *pcVar4 = cVar1 + '\x01';
  puVar3[1] = cVar1;
  puVar3[2] = 0xc;
  puVar3 = (undefined1 *)zb_put_next_htole16(puVar3 + 3,*(undefined2 *)(param_1 + 0x12));
  *puVar3 = *(undefined1 *)(param_1 + 0x14);
  zb_zcl_finish_and_send_packet
            (uVar2,puVar3 + 1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,*(undefined2 *)(param_1 + 0x10));
  return;
}

