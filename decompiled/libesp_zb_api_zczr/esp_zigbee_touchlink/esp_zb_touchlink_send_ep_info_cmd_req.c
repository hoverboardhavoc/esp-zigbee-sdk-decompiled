/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_touchlink.o -> esp_zb_touchlink_send_ep_info_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zb_touchlink_send_ep_info_cmd_req(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 *puVar4;
  char *pcVar5;
  
  iVar3 = zb_buf_get_out_func();
  if (iVar3 != 0) {
    puVar4 = (undefined1 *)zb_buf_reuse_func();
    *puVar4 = 9;
    pcVar5 = (char *)zb_zcl_get_ctx();
    cVar1 = *pcVar5;
    *pcVar5 = cVar1 + '\x01';
    puVar4[1] = cVar1;
    puVar4[2] = 0x40;
    memcpy(puVar4 + 3,(void *)0x11310,8);
    uVar2 = _DAT_0001130c;
    puVar4[0xb] = (char)_DAT_0001130c;
    puVar4[0xc] = (char)((ushort)uVar2 >> 8);
    puVar4[0xd] = *(undefined1 *)(param_1 + 10);
    uVar2 = *(undefined2 *)(param_1 + 0xc);
    puVar4[0xe] = (char)uVar2;
    puVar4[0xf] = (char)((ushort)uVar2 >> 8);
    uVar2 = *(undefined2 *)(param_1 + 0xe);
    puVar4[0x10] = (char)uVar2;
    puVar4[0x11] = (char)((ushort)uVar2 >> 8);
    puVar4[0x12] = *(undefined1 *)(param_1 + 0x10);
    zb_zcl_finish_and_send_packet
              (iVar3,puVar4 + 0x13,param_1,2,*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),0xc05e,0x1000);
  }
  return;
}

