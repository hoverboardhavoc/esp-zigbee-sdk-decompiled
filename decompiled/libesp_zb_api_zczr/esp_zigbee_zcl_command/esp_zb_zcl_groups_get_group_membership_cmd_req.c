/*
 * Last changed at upstream commit d50acd5408f73d4459b46a949332bb6e32f97543
 * https://github.com/espressif/esp-zigbee-sdk/commit/d50acd5408f73d4459b46a949332bb6e32f97543
 * Upstream date: 2023-09-08 17:20:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.4(89250ad3)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_groups_get_group_membership_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_groups_get_group_membership_cmd_req(int param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  uVar3 = zb_buf_get_out_func();
  if (10 < *(byte *)(param_1 + 0x10)) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC4,uVar5,0x10000);
  }
  pcVar4 = (char *)zb_zcl_start_command_header(uVar3,1,0,2,0);
  cVar1 = *(char *)(param_1 + 0x10);
  *pcVar4 = cVar1;
  pcVar4 = pcVar4 + 1;
  if (cVar1 != '\0') {
    for (uVar2 = 0; uVar2 < *(byte *)(param_1 + 0x10); uVar2 = uVar2 + 1 & 0xff) {
      pcVar4 = (char *)zb_put_next_htole16(*(undefined2 *)((uVar2 + 8) * 2 + param_1 + 2));
    }
  }
  zb_zcl_finish_and_send_packet
            (uVar3,pcVar4,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,4);
  return;
}

