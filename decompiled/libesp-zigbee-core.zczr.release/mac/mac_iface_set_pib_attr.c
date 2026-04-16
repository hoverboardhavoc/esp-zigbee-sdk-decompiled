/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_iface_set_pib_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_iface_set_pib_attr(mac_interface_t *iface,mac_pib_attr_t pib_attr,void *value)

{
  mac_device *dev;
  uint uVar1;
  uint8_t channel;
  uint uVar2;
  undefined3 in_register_0000202d;
  undefined4 uVar3;
  
  uVar1 = CONCAT31(in_register_0000202d,pib_attr);
  dev = (mac_device *)iface->dev;
  if (value == (void *)0x0) {
    return 2;
  }
  if (uVar1 == 0x50) {
                    /* WARNING: Load size is inaccurate */
    mac_set_panid(dev,*value);
    return 0;
  }
  if (uVar1 < 0x51) {
    if (uVar1 == 0x49) {
                    /* WARNING: Load size is inaccurate */
      (dev->pib).bsn = *value;
      return 0;
    }
    if (uVar1 < 0x4a) {
      if (uVar1 == 0x45) {
                    /* WARNING: Load size is inaccurate */
        (dev->pib).beacon_payload = *value;
        return 0;
      }
      if (0x45 < uVar1) {
        if (uVar1 == 0x46) {
                    /* WARNING: Load size is inaccurate */
          (dev->pib).beacon_payload_len = *value;
          return 0;
        }
        uVar2 = 0xf4;
        if (uVar1 != 0x47) goto _L0;
        goto _L0;
      }
      if (uVar1 == 0x40) {
                    /* WARNING: Load size is inaccurate */
        uVar3 = *(undefined4 *)((int)value + 4);
        *(undefined4 *)&(dev->pib).extended_address.field_0 = *value;
        *(undefined4 *)((int)&(dev->pib).extended_address.field_0 + 4) = uVar3;
        mac_pal_set_extaddr(dev);
        return 0;
      }
      if (uVar1 == 0x41) {
                    /* WARNING: Load size is inaccurate */
        (dev->pib).field_0x2a = (dev->pib).field_0x2a & 0xfe | *value & 1;
        return 0;
      }
    }
    else {
      if (uVar1 == 0x4c) {
                    /* WARNING: Load size is inaccurate */
        (dev->pib).dsn = *value;
        return 0;
      }
      if (uVar1 < 0x4d) {
        if (uVar1 == 0x4a) {
          memcpy(&(dev->pib).coord_extaddr,value,8);
          return 0;
        }
                    /* WARNING: Load size is inaccurate */
        (dev->pib).coord_shortaddr = *value;
        return 0;
      }
      if (uVar1 == 0x4e) {
                    /* WARNING: Load size is inaccurate */
        (dev->pib).max_csma_backoffs = *value;
        return 0;
      }
      if (uVar1 == 0x4f) {
                    /* WARNING: Load size is inaccurate */
        (dev->pib).min_be = *value;
        return 0;
      }
    }
  }
  else {
    if (uVar1 == 0x58) {
                    /* WARNING: Load size is inaccurate */
      (dev->pib).max_frame_total_wait_time = *value;
      return 0;
    }
    if (uVar1 < 0x59) {
      if (uVar1 == 0x54) {
_L0:
        uVar2 = 0xfb;
        goto _L0;
      }
      if (uVar1 < 0x55) {
        if (uVar1 == 0x52) {
                    /* WARNING: Load size is inaccurate */
          if ((uint)*value == (*(uint *)&(dev->pib).transaction_persistence_time >> 0x11 & 1)) {
            return 0;
          }
          (dev->pib).field_0x2a = (dev->pib).field_0x2a & 0xfd | (byte)((*value & 1) << 1);
          mac_pal_set_rx_when_idle();
_L0:
          mac_do_idle(dev);
          return 0;
        }
        if (uVar1 == 0x53) {
                    /* WARNING: Load size is inaccurate */
          (dev->pib).short_address = *value;
          mac_pal_set_shortaddr();
          return 0;
        }
      }
      else {
        if (uVar1 == 0x55) {
                    /* WARNING: Load size is inaccurate */
          (dev->pib).transaction_persistence_time = *value;
          return 0;
        }
        if (uVar1 == 0x57) {
                    /* WARNING: Load size is inaccurate */
          (dev->pib).max_be = *value;
          return 0;
        }
      }
    }
    else {
      if (uVar1 == 0x60) goto _L0;
      if (uVar1 < 0x61) {
        if (uVar1 == 0x5a) {
                    /* WARNING: Load size is inaccurate */
          (dev->pib).rsp_wait_time = *value;
          return 0;
        }
        if (uVar1 == 0x5d) goto _L0;
        if (uVar1 == 0x59) {
                    /* WARNING: Load size is inaccurate */
          (dev->pib).max_frame_retries = *value;
          return 0;
        }
      }
      else {
        if (uVar1 == 0x62) {
                    /* WARNING: Load size is inaccurate */
          if ((*value & 0x7ffffff) == 0) {
            if (((dev->ctx).field_0x70 & 2) == 0) {
              return 0;
            }
            (dev->ctx).field_0x70 = (dev->ctx).field_0x70 & 0xfd;
            (dev->ctx).phy_channel_page = (dev->ctx).pan_channel_page;
            (dev->ctx).phy_channel = (dev->ctx).pan_channel;
          }
          else {
            uVar1 = __ctzsi2(value);
            if ((((dev->pib).supported_channel_page.u32 & 0x7ffffff) >> (uVar1 & 0x1f) & 1) == 0) {
              return 0;
            }
                    /* WARNING: Load size is inaccurate */
            uVar3 = *value;
            (dev->ctx).field_0x70 = (dev->ctx).field_0x70 | 2;
            (dev->ctx).phy_channel_page = (byte)((uint)uVar3 >> 0x1b);
            (dev->ctx).phy_channel = (uint8_t)uVar1;
          }
          goto _L0;
        }
        if (uVar1 == 99) goto _L0;
        if (uVar1 == 0x61) {
                    /* WARNING: Load size is inaccurate */
          uVar1 = *value;
          if ((uVar1 & 0x7ffffff) != 0) {
            channel = __ctzsi2(uVar1 & 0x7ffffff);
            mac_set_pan_channel(dev,(byte)(uVar1 >> 0x1b),channel);
            return 0;
          }
          return 2;
        }
      }
    }
  }
  uVar2 = 0xf4;
_L0:
  return uVar2 | 0x100;
}

