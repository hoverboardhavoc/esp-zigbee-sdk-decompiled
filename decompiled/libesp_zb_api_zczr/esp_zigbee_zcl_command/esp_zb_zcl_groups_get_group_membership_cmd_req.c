/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
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
  
  uVar3 = zb_buf_get_out_func();
  pcVar4 = (char *)zb_zcl_start_command_header(1,0,2,0);
  cVar1 = *(char *)(param_1 + 0x10);
  *pcVar4 = cVar1;
  pcVar4 = pcVar4 + 1;
  if (cVar1 != '\0') {
    for (uVar2 = 0; uVar2 < *(byte *)(param_1 + 0x10); uVar2 = uVar2 + 1 & 0xff) {
      pcVar4 = (char *)zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + uVar2 * 2));
    }
  }
  zb_zcl_finish_and_send_packet
            (uVar3,pcVar4,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,4);
  return;
}

