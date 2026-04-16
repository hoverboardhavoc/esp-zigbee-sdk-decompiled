/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> cvc_enhanced_move_to_hue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
cvc_enhanced_move_to_hue
          (uint8_t ep_id,ezb_zcl_color_control_enhanced_move_to_hue_cmd_payload_t *payload)

{
  byte bVar1;
  ezb_zcl_status_t eVar2;
  zcl_attr_desc_t *pzVar3;
  int iVar4;
  undefined1 local_30 [4];
  zcl_cvc_input_t input;
  
  if (payload == (ezb_zcl_color_control_enhanced_move_to_hue_cmd_payload_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x6df,
                  "cvc_enhanced_move_to_hue","payload");
_L0:
    eVar2 = 0x85;
  }
  else {
    input.ep_id = '\0';
    input._1_3_ = 0;
    input.begin = 0;
    input.duration = 0;
    local_30._1_3_ = 0;
    local_30[0] = ep_id;
    input.end = 1;
    input._12_4_ = ZEXT24(payload->transition_time);
    input._20_4_ = cvc_enhanced_hue_output_handler;
    input.cb = (zcl_cvc_output_callback_t)0x4000;
    pzVar3 = color_control_srv_get_attr_desc(ep_id,0x4000);
    if (pzVar3 == (zcl_attr_desc_t *)0x0) {
      return 0x86;
    }
                    /* WARNING: Load size is inaccurate */
    input._0_4_ = ZEXT24(*pzVar3->data_p);
    input.begin = (int32_t)payload->enhanced_hue;
    bVar1 = payload->direction;
    if (bVar1 == 2) {
      if ((uint)input.begin < (uint)input._0_4_) {
        input.begin = input.begin + 0x10000;
      }
    }
    else if (bVar1 < 3) {
      if (bVar1 == 0) {
        if ((uint)input.begin < (uint)input._0_4_) {
          iVar4 = input._0_4_ - input.begin;
        }
        else {
          iVar4 = input.begin - input._0_4_;
        }
        if ((uint)input._0_4_ < (uint)input.begin == 0x8000 < iVar4) {
          if ((uint)input._0_4_ < (uint)input.begin) {
            input.begin = input.begin - 0x10000;
          }
        }
        else if ((uint)input.begin < (uint)input._0_4_) {
          input.begin = input.begin + 0x10000;
        }
      }
      else {
        if (bVar1 != 1) goto _L0;
        if ((uint)input.begin < (uint)input._0_4_) {
          iVar4 = input._0_4_ - input.begin;
        }
        else {
          iVar4 = input.begin - input._0_4_;
        }
        if ((uint)input._0_4_ < (uint)input.begin == 0x8000 < iVar4) {
          if ((uint)input.begin < (uint)input._0_4_) {
            input.begin = input.begin + 0x10000;
          }
        }
        else if ((uint)input._0_4_ < (uint)input.begin) {
          input.begin = input.begin - 0x10000;
        }
      }
    }
    else {
      if (bVar1 != 3) {
        return 0x85;
      }
      if ((uint)input._0_4_ < (uint)input.begin) {
        input.begin = input.begin - 0x10000;
      }
    }
    eVar2 = schedule_cvc_color_line(ep_id,(zcl_cvc_input_t *)local_30);
  }
  return eVar2;
}

