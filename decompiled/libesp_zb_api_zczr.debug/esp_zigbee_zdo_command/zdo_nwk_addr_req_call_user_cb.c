/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zdo_command.o -> zdo_nwk_addr_req_call_user_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_nwk_addr_req_call_user_cb(undefined4 param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined2 uStack_30;
  undefined1 *puStack_2c;
  undefined1 uStack_28;
  char cStack_27;
  undefined1 uStack_26;
  int iStack_24;
  
  if (param_2 != (code *)0x0) {
    iVar1 = zb_buf_begin_func();
    uStack_38 = 0xffffffff;
    uStack_34 = 0xffffffff;
    uStack_30 = ZDO_INVALID_SHORT_ADDR;
    puStack_2c = (undefined1 *)0x0;
    if (*(char *)(iVar1 + 1) == '\0') {
      zb_memcpy8(&uStack_38,iVar1 + 2);
      uStack_30 = *(undefined2 *)(iVar1 + 10);
      uVar2 = zb_buf_len_func(param_1);
      if (0xc < uVar2) {
        cStack_27 = *(char *)(iVar1 + 0xc);
        if (cStack_27 != '\0') {
          uStack_28 = *(undefined1 *)(iVar1 + 0xd);
          iStack_24 = iVar1 + 0xe;
          iVar3 = zb_buf_len_func(param_1);
          iVar4 = zb_buf_get_ptr_off_func(param_1,iVar1 + 0xe);
          uStack_26 = (undefined1)((uint)(iVar3 - iVar4) >> 1);
          puStack_2c = &uStack_28;
        }
      }
    }
    (*param_2)(*(undefined1 *)(iVar1 + 1),&uStack_38,param_3);
  }
  return;
}

