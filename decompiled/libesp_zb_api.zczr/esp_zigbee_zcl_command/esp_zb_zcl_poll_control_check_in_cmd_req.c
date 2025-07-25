/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_poll_control_check_in_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte esp_zb_zcl_poll_control_check_in_cmd_req(int param_1)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  char *pcVar7;
  undefined2 uVar8;
  
  if ((param_1 != 0) && (iVar4 = zb_buf_get_out_func(), iVar4 != 0)) {
    iVar5 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
    uVar8 = 0x104;
    if (iVar5 != 0) {
      uVar8 = *(undefined2 *)(iVar5 + 1);
    }
    puVar6 = (undefined1 *)zb_buf_reuse_func(iVar4);
    *puVar6 = 0x19;
    pcVar7 = (char *)zb_zcl_get_ctx();
    cVar2 = *pcVar7;
    *pcVar7 = cVar2 + '\x01';
    puVar6[1] = cVar2;
    puVar6[2] = 0;
    zb_zcl_finish_and_send_packet
              (iVar4,puVar6 + 3,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar8,0x20);
    pbVar3 = (byte *)zb_buf_begin_func(iVar4);
    if ((*pbVar3 & 4) == 0) {
      iVar4 = 1;
    }
    else {
      iVar4 = 3;
    }
    return pbVar3[iVar4];
  }
  pbVar3 = (byte *)zb_zcl_get_ctx();
  bVar1 = *pbVar3;
  *pbVar3 = bVar1 + 1;
  return bVar1;
}

