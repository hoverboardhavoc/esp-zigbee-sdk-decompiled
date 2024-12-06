/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_groups_get_group_membership_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_groups_get_group_membership_cmd_req(int param_1)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  byte *pbVar7;
  uint uVar8;
  
  uVar3 = 0x104;
  iVar4 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar4 != 0) {
    uVar3 = *(undefined2 *)(iVar4 + 1);
  }
  iVar4 = zb_buf_get_out_func();
  if (iVar4 == 0) {
    pbVar7 = (byte *)zb_zcl_get_ctx();
    bVar2 = *pbVar7;
    *pbVar7 = bVar2 + 1;
    return bVar2;
  }
  pcVar5 = (char *)zb_zcl_start_command_header(1,0,2,0);
  cVar1 = *(char *)(param_1 + 0x10);
  pcVar6 = pcVar5 + 1;
  *pcVar5 = cVar1;
  if (cVar1 != '\0') {
    for (uVar8 = 0; uVar8 < *(byte *)(param_1 + 0x10); uVar8 = uVar8 + 1 & 0xff) {
      pcVar6 = (char *)zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + uVar8 * 2));
    }
  }
  zb_zcl_finish_and_send_packet
            (iVar4,pcVar6,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),uVar3,4);
  pbVar7 = (byte *)zb_buf_begin_func(iVar4);
  if ((*pbVar7 & 4) == 0) {
    iVar4 = 1;
  }
  else {
    iVar4 = 3;
  }
  return pbVar7[iVar4];
}

