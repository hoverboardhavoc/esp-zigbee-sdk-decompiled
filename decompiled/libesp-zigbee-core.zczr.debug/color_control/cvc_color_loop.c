/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> cvc_color_loop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: input */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
cvc_color_loop(uint8_t ep_id,ezb_zcl_color_control_color_loop_set_cmd_payload_t *payload)

{
  uint8_t uVar1;
  zcl_attr_desc_t *pzVar2;
  zcl_attr_desc_t *unaff_s2;
  zcl_attr_desc_t *unaff_s3;
  zcl_attr_desc_t *unaff_s4;
  zcl_attr_desc_t *unaff_s6;
  undefined1 local_40 [4];
  zcl_cvc_input_t input;
  
  if (payload == (ezb_zcl_color_control_color_loop_set_cmd_payload_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x82b,
                  "cvc_color_loop","payload");
  }
  else {
    input.ep_id = '\0';
    input._1_3_ = 0;
    input.begin = 0;
    input.end._0_2_ = 1;
    input.quant = 0;
    input._14_2_ = 0;
    input.duration._0_1_ = 0;
    input._20_4_ = cvc_enhanced_hue_output_handler;
    input.cb = (zcl_cvc_output_callback_t)0x4000;
    local_40[0] = ep_id;
    unaff_s2 = color_control_srv_get_attr_desc(ep_id,0x4002);
    unaff_s3 = color_control_srv_get_attr_desc(ep_id,0x4003);
    unaff_s4 = color_control_srv_get_attr_desc(ep_id,0x4004);
    pzVar2 = color_control_srv_get_attr_desc(ep_id,0x4005);
    unaff_s6 = color_control_srv_get_attr_desc(ep_id,0x4000);
    if (unaff_s2 == (zcl_attr_desc_t *)0x0) {
      return 0x86;
    }
    if (unaff_s3 == (zcl_attr_desc_t *)0x0) {
      return 0x86;
    }
    if (unaff_s4 == (zcl_attr_desc_t *)0x0) {
      return 0x86;
    }
    if (pzVar2 == (zcl_attr_desc_t *)0x0) {
      return 0x86;
    }
    if (unaff_s6 == (zcl_attr_desc_t *)0x0) {
      return 0x86;
    }
    if ((payload->update_flags & 2) != 0) {
      *(uint8_t *)unaff_s3->data_p = payload->direction;
    }
    if ((payload->update_flags & 4) != 0) {
      *(uint16_t *)unaff_s4->data_p = payload->time;
    }
    if ((payload->update_flags & 8) != 0) {
      *(uint16_t *)pzVar2->data_p = payload->start_hue;
    }
    if ((payload->update_flags & 1) == 0) goto _L0;
    uVar1 = payload->action;
    if (uVar1 != '\x01') {
      if (uVar1 == '\x02') {
        color_control_copy_attr_u16(ep_id,0x4000,0x4006);
        *(undefined1 *)unaff_s2->data_p = 1;
      }
      else {
        if (uVar1 != '\0') {
          return 0x87;
        }
                    /* WARNING: Load size is inaccurate */
        if (*unaff_s2->data_p == '\x01') {
          *(char *)unaff_s2->data_p = '\0';
          color_control_copy_attr_u16(ep_id,0x4006,0x4000);
        }
      }
      goto _L0;
    }
  }
  color_control_copy_attr_u16(ep_id,0x4000,0x4005);
  *(undefined1 *)unaff_s2->data_p = 1;
_L0:
                    /* WARNING: Load size is inaccurate */
  if (*unaff_s2->data_p == '\0') {
    stop_cvc_color(ep_id,'\x03');
  }
  else {
                    /* WARNING: Load size is inaccurate */
    input._12_4_ = (uint)*unaff_s4->data_p * 10;
                    /* WARNING: Load size is inaccurate */
    input._0_4_ = ZEXT24(*unaff_s6->data_p);
                    /* WARNING: Load size is inaccurate */
    if (*unaff_s3->data_p == '\0') {
      input.begin = input._0_4_ + 0x10000;
    }
    else {
      input.begin = input._0_4_ - 0x10000;
    }
    schedule_cvc_color_line(ep_id,(zcl_cvc_input_t *)local_40);
  }
  return '\0';
}

