/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_iface_set_pib_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_iface_set_pib_attr(mac_interface_t *iface,mac_pib_attr_t pib_attr,void *value)

{
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  uint8_t uVar5;
  uint8_t uVar6;
  mac_device *dev;
  uint8_t uVar7;
  uint uVar8;
  undefined3 in_register_0000202d;
  
  uVar8 = CONCAT31(in_register_0000202d,pib_attr);
  dev = (mac_device *)iface->dev;
  if (value == (void *)0x0) {
    uVar8 = 2;
  }
  else if (uVar8 == 0x50) {
                    /* WARNING: Load size is inaccurate */
    mac_set_panid(dev,*value);
    uVar8 = 0;
  }
  else {
    if (uVar8 < 0x51) {
      if (uVar8 == 0x49) {
                    /* WARNING: Load size is inaccurate */
        (dev->pib).bsn = *value;
        return 0;
      }
      if (uVar8 < 0x4a) {
        if (uVar8 == 0x45) {
                    /* WARNING: Load size is inaccurate */
          (dev->pib).beacon_payload = *value;
          return 0;
        }
        if (uVar8 < 0x46) {
          if (uVar8 == 0x40) {
            mac_set_extended_address(dev,(ezb_extaddr_t *)value);
            return 0;
          }
          if (uVar8 == 0x41) {
                    /* WARNING: Load size is inaccurate */
            (dev->pib).field_0x2a = (dev->pib).field_0x2a & 0xfe | *value & 1;
            return 0;
          }
          uVar8 = 0xf4;
        }
        else {
          if (uVar8 == 0x46) {
                    /* WARNING: Load size is inaccurate */
            (dev->pib).beacon_payload_len = *value;
            return 0;
          }
          if (uVar8 == 0x47) {
            uVar8 = 0xfb;
          }
          else {
            uVar8 = 0xf4;
          }
        }
      }
      else {
        if (uVar8 == 0x4c) {
                    /* WARNING: Load size is inaccurate */
          (dev->pib).dsn = *value;
          return 0;
        }
        if (uVar8 < 0x4d) {
          if (uVar8 == 0x4a) {
                    /* WARNING: Load size is inaccurate */
            uVar7 = *(uint8_t *)((int)value + 1);
            uVar1 = *(uint8_t *)((int)value + 2);
            uVar2 = *(uint8_t *)((int)value + 3);
            uVar3 = *(uint8_t *)((int)value + 4);
            uVar4 = *(uint8_t *)((int)value + 5);
            uVar5 = *(uint8_t *)((int)value + 6);
            uVar6 = *(uint8_t *)((int)value + 7);
            (dev->pib).coord_extaddr.field_0.u8[0] = *value;
            (dev->pib).coord_extaddr.field_0.u8[1] = uVar7;
            (dev->pib).coord_extaddr.field_0.u8[2] = uVar1;
            (dev->pib).coord_extaddr.field_0.u8[3] = uVar2;
            (dev->pib).coord_extaddr.field_0.u8[4] = uVar3;
            (dev->pib).coord_extaddr.field_0.u8[5] = uVar4;
            (dev->pib).coord_extaddr.field_0.u8[6] = uVar5;
            (dev->pib).coord_extaddr.field_0.u8[7] = uVar6;
            return 0;
          }
          if (uVar8 == 0x4b) {
                    /* WARNING: Load size is inaccurate */
            (dev->pib).coord_shortaddr = *value;
            return 0;
          }
          uVar8 = 0xf4;
        }
        else {
          if (uVar8 == 0x4e) {
                    /* WARNING: Load size is inaccurate */
            (dev->pib).max_csma_backoffs = *value;
            return 0;
          }
          if (uVar8 == 0x4f) {
                    /* WARNING: Load size is inaccurate */
            (dev->pib).min_be = *value;
            return 0;
          }
          uVar8 = 0xf4;
        }
      }
    }
    else {
      if (uVar8 == 0x58) {
                    /* WARNING: Load size is inaccurate */
        (dev->pib).max_frame_total_wait_time = *value;
        return 0;
      }
      if (uVar8 < 0x59) {
        if (uVar8 == 0x54) {
          uVar8 = 0xfb;
        }
        else if (uVar8 < 0x55) {
          if (uVar8 == 0x52) {
                    /* WARNING: Load size is inaccurate */
            mac_set_rx_on_when_idle(dev,*value);
            return 0;
          }
          if (uVar8 == 0x53) {
                    /* WARNING: Load size is inaccurate */
            mac_set_short_address(dev,*value);
            return 0;
          }
          uVar8 = 0xf4;
        }
        else {
          if (uVar8 == 0x55) {
                    /* WARNING: Load size is inaccurate */
            (dev->pib).transaction_persistence_time = *value;
            return 0;
          }
          if (uVar8 == 0x57) {
                    /* WARNING: Load size is inaccurate */
            (dev->pib).max_be = *value;
            return 0;
          }
          uVar8 = 0xf4;
        }
      }
      else if (uVar8 == 0x60) {
        uVar8 = 0xfb;
      }
      else if (uVar8 < 0x61) {
        if (uVar8 == 0x5a) {
                    /* WARNING: Load size is inaccurate */
          (dev->pib).rsp_wait_time = *value;
          return 0;
        }
        if (uVar8 == 0x5d) {
          uVar8 = 0xfb;
        }
        else {
          if (uVar8 == 0x59) {
                    /* WARNING: Load size is inaccurate */
            (dev->pib).max_frame_retries = *value;
            return 0;
          }
          uVar8 = 0xf4;
        }
      }
      else {
        if (uVar8 == 0x62) {
                    /* WARNING: Load size is inaccurate */
          if ((*value & 0x7ffffff) != 0) {
                    /* WARNING: Load size is inaccurate */
            uVar8 = *value;
            uVar7 = __ctzsi2(uVar8 & 0x7ffffff);
            mac_set_temporary_channel(dev,(byte)(uVar8 >> 0x1b),uVar7);
            return 0;
          }
          mac_clear_temporary_channel(dev);
          return 0;
        }
        if (uVar8 == 99) {
          uVar8 = 0xfb;
        }
        else {
          if (uVar8 == 0x61) {
                    /* WARNING: Load size is inaccurate */
            if ((*value & 0x7ffffff) != 0) {
                    /* WARNING: Load size is inaccurate */
              uVar8 = *value;
              uVar7 = __ctzsi2(uVar8 & 0x7ffffff);
              mac_set_pan_channel(dev,(byte)(uVar8 >> 0x1b),uVar7);
              return 0;
            }
            return 2;
          }
          uVar8 = 0xf4;
        }
      }
    }
    uVar8 = uVar8 | 0x100;
  }
  return uVar8;
}

