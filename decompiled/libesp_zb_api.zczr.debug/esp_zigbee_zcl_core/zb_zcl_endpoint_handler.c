/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_core.o -> zb_zcl_endpoint_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_endpoint_handler(int param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  uVar7 = param_1 - 1U & 0xff;
  iVar4 = zb_bufpool_storage_bufid_to_buf(uVar7);
  sVar1 = *(short *)(iVar4 + 4);
  iVar4 = zb_bufpool_storage_bufid_to_buf(uVar7);
  sVar2 = *(short *)(iVar4 + 6);
  iVar4 = zb_buf_get_tail_func(param_1,0x1b);
  if (*(char *)(iVar4 + 0x16) == '\0') {
    iVar4 = zb_buf_get_tail_func(param_1,0x1b);
    sVar3 = *(short *)(iVar4 + 0xf);
    puVar6 = s_endpoint_handler_list;
    if (sVar3 < 0) {
      sVar3 = -0x8000;
    }
    for (; (short *)(puVar6 + -2) != (short *)0xfffffff8; puVar6 = (undefined4 *)*puVar6) {
      if (*(short *)(puVar6 + -2) == sVar3) {
        iVar4 = (*(code *)puVar6[-1])(param_1,(code *)puVar6[-1]);
        goto _L0;
      }
    }
    iVar4 = 0;
_L0:
    if (-1 < sVar3) {
      if (iVar4 != 0) {
        return;
      }
      if (s_privilege_command_handler != (code *)0x0) {
        iVar4 = (*s_privilege_command_handler)(param_1);
      }
    }
  }
  else {
    iVar4 = zb_zcl_general_cmd_handler(param_1);
  }
  if ((iVar4 == 0) && (zcl_raw_command_cb != (code *)0x0)) {
    iVar4 = zb_bufpool_storage_bufid_to_buf(uVar7);
    if ((*(short *)(iVar4 + 4) != sVar1) ||
       (iVar4 = zb_bufpool_storage_bufid_to_buf(uVar7), *(short *)(iVar4 + 6) != sVar2)) {
      iVar4 = zb_bufpool_storage_bufid_to_buf(uVar7);
      *(char *)(iVar4 + 4) = (char)sVar1;
      *(char *)(iVar4 + 5) = (char)((ushort)sVar1 >> 8);
      iVar4 = zb_bufpool_storage_bufid_to_buf(uVar7);
      *(char *)(iVar4 + 6) = (char)sVar2;
      *(char *)(iVar4 + 7) = (char)((ushort)sVar2 >> 8);
      uVar5 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_ZCL_CORE",&_LC3,uVar5,"ESP_ZIGBEE_ZCL_CORE");
    }
    (*zcl_raw_command_cb)(param_1,zcl_raw_command_cb);
  }
  return;
}

