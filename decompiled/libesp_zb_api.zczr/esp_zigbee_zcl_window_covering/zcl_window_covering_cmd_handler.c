/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_window_covering.o -> zcl_window_covering_cmd_handler
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
  undefined2 uStack_14;
  undefined2 uStack_12;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  uStack_1c = 0;
  uStack_14 = 0;
  _uStack_18 = CONCAT22(0x102,(ushort)*(byte *)(iVar1 + 4));
  uStack_12 = 0;
  puVar2 = (uint *)zb_buf_get_tail_func(param_1,0x38);
  uVar3 = *puVar2;
  if (uVar3 == 0x53) {
    uStack_14 = 4;
_L0:
    iVar1 = zb_buf_get_tail_func(param_1,0x38);
    uStack_12 = **(undefined2 **)(iVar1 + 0x10);
  }
  else {
    if (0x53 < uVar3) goto _L0;
    if (uVar3 == 0x51) {
      uStack_14 = 1;
    }
    else if (uVar3 == 0x52) {
      uStack_14 = 2;
    }
    else if (uVar3 == 0x50) {
      uStack_14 = 0;
    }
    else {
      do {
        zb_assert(0x10000,0x5a);
_L0:
        if (uVar3 == 0x55) {
          uStack_14 = 7;
          goto _L0;
        }
        if (uVar3 == 0x56) {
          uStack_14 = 8;
          goto _L0;
        }
      } while (uVar3 != 0x54);
      uStack_14 = 5;
_L0:
      iVar1 = zb_buf_get_tail_func(param_1,0x38);
      uStack_12 = CONCAT11(uStack_12._1_1_,**(undefined1 **)(iVar1 + 0x10));
    }
  }
  esp_zb_core_action_handler_schedule(0x30,&uStack_1c);
  esp_err_to_zb_ret();
  return;
}

