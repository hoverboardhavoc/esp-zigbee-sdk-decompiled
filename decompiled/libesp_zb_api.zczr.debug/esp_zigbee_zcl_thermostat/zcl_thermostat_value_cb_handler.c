/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_thermostat.o -> zcl_thermostat_value_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void zcl_thermostat_value_cb_handler(int param_1)

{
  int iVar1;
  undefined4 uStack_44;
  ushort uStack_40;
  undefined2 uStack_3e;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_20;
  undefined1 uStack_1c;
  undefined2 uStack_1a;
  undefined1 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  
  if (param_1 != 0) {
    iVar1 = zb_buf_get_tail_func(0x38);
    local_20 = 0;
    uStack_1c = *(undefined1 *)(iVar1 + 4);
    uStack_1a = 0x201;
    uStack_18 = *(undefined1 *)(iVar1 + 0xc);
    uStack_16 = *(undefined2 *)(iVar1 + 0xd);
    uStack_14 = *(undefined2 *)(iVar1 + 0xf);
    esp_zb_core_action_handler_schedule(7,&local_20);
    esp_err_to_zb_ret();
    return;
  }
  iVar1 = zb_assert(0x10000,0x66);
  if (iVar1 != 0) {
    iVar1 = zb_buf_get_tail_func(0x38);
    uStack_44 = 0;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    _uStack_40 = CONCAT22(0x201,(ushort)*(byte *)(iVar1 + 4));
    uStack_3c = zb_ret_to_esp_err(*(undefined4 *)(iVar1 + 8));
    uStack_38 = CONCAT22(*(undefined2 *)(iVar1 + 0x11),*(undefined2 *)(iVar1 + 0xd));
    uStack_34 = *(undefined4 *)(iVar1 + 0x13);
    esp_zb_core_action_handler_schedule(0x32,&uStack_44);
    esp_err_to_zb_ret();
    return;
  }
  zb_assert(0x10000,0x50);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

