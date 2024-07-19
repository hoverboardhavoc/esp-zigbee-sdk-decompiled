/*
 * Last changed at upstream commit 280ac146dc8285567eab4df113b3f6356493fe0b
 * https://github.com/espressif/esp-zigbee-sdk/commit/280ac146dc8285567eab4df113b3f6356493fe0b
 * Upstream date: 2024-07-19 11:49:15 +0800
 * Upstream subject: esp-zigbee-lib:(94bd7a1a)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_window_covering.o -> zcl_window_covering_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_window_covering_cmd_handler(undefined4 param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uStack_1c;
  ushort uStack_18;
  undefined2 uStack_16;
  undefined4 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  uStack_1c = 0;
  _uStack_18 = CONCAT22(0x102,(ushort)*(byte *)(iVar1 + 4));
  uStack_14 = 0;
  puVar2 = (uint *)zb_buf_get_tail_func(param_1,0x38);
  uVar3 = *puVar2;
  if (uVar3 == 0x52) {
    uStack_14 = CONCAT22(uStack_14._2_2_,4);
    iVar1 = zb_buf_get_tail_func(param_1,0x38);
    uStack_14 = CONCAT22(**(undefined2 **)(iVar1 + 0x10),(undefined2)uStack_14);
  }
  else if (uVar3 < 0x53) {
    if (uVar3 == 0x50) {
      uStack_14 = CONCAT22(uStack_14._2_2_,1);
    }
    else if (uVar3 == 0x51) {
      uStack_14 = CONCAT22(uStack_14._2_2_,2);
    }
    else {
      if (uVar3 != 0x4f) {
_L0:
        zb_assert(0x10000,0x5a);
        zb_zcl_window_covering_init_server();
        zb_zcl_device_cb_register(0x4f,zcl_window_covering_cmd_handler);
        zb_zcl_device_cb_register(0x50,zcl_window_covering_cmd_handler);
        zb_zcl_device_cb_register(0x51,zcl_window_covering_cmd_handler);
        zb_zcl_device_cb_register(0x52,zcl_window_covering_cmd_handler);
        zb_zcl_device_cb_register(0x53,zcl_window_covering_cmd_handler);
        zb_zcl_device_cb_register(0x54,zcl_window_covering_cmd_handler);
        zb_zcl_device_cb_register(0x55,zcl_window_covering_cmd_handler);
        return;
      }
      uStack_14 = (uint)uStack_14._2_2_ << 0x10;
    }
  }
  else if (uVar3 == 0x54) {
    uStack_14 = CONCAT22(uStack_14._2_2_,7);
    iVar1 = zb_buf_get_tail_func(param_1,0x38);
    uStack_14 = CONCAT22(**(undefined2 **)(iVar1 + 0x10),(undefined2)uStack_14);
  }
  else if (uVar3 == 0x55) {
    uStack_14 = CONCAT22(uStack_14._2_2_,8);
    iVar1 = zb_buf_get_tail_func(param_1,0x38);
    uStack_14._0_3_ = CONCAT12(**(undefined1 **)(iVar1 + 0x10),(undefined2)uStack_14);
  }
  else {
    if (uVar3 != 0x53) goto _L0;
    uStack_14 = CONCAT22(uStack_14._2_2_,5);
    iVar1 = zb_buf_get_tail_func(param_1,0x38);
    uStack_14._0_3_ = CONCAT12(**(undefined1 **)(iVar1 + 0x10),(undefined2)uStack_14);
  }
  esp_zb_core_action_handler_schedule(0x30,&uStack_1c);
  esp_err_to_zb_ret();
  return;
}

