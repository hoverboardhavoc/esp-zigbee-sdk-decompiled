/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
color_control_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t ep_id,void *value)

{
  ezb_zcl_status_t eVar1;
  undefined2 in_register_0000202a;
  uint uVar2;
  uint16_t uStack_14;
  uint16_t uStack_12;
  uint16_t min_color_temperature;
  uint16_t max_color_temperature;
  
  uVar2 = CONCAT22(in_register_0000202a,attr_id);
  if (uVar2 == 4) {
                    /* WARNING: Load size is inaccurate */
    if (*value < 0xff00) {
      eVar1 = '\0';
    }
    else {
      eVar1 = '\x01';
    }
  }
  else if (uVar2 < 5) {
    if (uVar2 == 1) {
                    /* WARNING: Load size is inaccurate */
      if (*value == -1) {
        eVar1 = '\x01';
      }
      else {
        eVar1 = '\0';
      }
    }
    else if (uVar2 == 3) {
                    /* WARNING: Load size is inaccurate */
      if (*value < 0xff00) {
        eVar1 = '\0';
      }
      else {
        eVar1 = '\x01';
      }
    }
    else if (uVar2 == 0) {
                    /* WARNING: Load size is inaccurate */
      if (*value == -1) {
        eVar1 = '\x01';
      }
      else {
        eVar1 = '\0';
      }
    }
    else {
      eVar1 = '\0';
    }
  }
  else if (uVar2 == 8) {
                    /* WARNING: Load size is inaccurate */
    if (*value < 3) {
      eVar1 = '\0';
    }
    else {
      eVar1 = '\x01';
    }
  }
  else if (uVar2 == 0x400a) {
                    /* WARNING: Load size is inaccurate */
    if (*value < 0x20) {
      eVar1 = '\0';
    }
    else {
      eVar1 = '\x01';
    }
  }
  else if (uVar2 == 7) {
    uStack_14 = 0;
    uStack_12 = 0;
    color_control_get_color_temperature_range(ep_id,&uStack_14,&uStack_12);
                    /* WARNING: Load size is inaccurate */
    if (*value < uStack_14) {
      eVar1 = '\x01';
    }
    else if (uStack_12 < *value) {
      eVar1 = '\x01';
    }
    else {
      eVar1 = '\0';
    }
  }
  else {
    eVar1 = '\0';
  }
  return eVar1;
}

