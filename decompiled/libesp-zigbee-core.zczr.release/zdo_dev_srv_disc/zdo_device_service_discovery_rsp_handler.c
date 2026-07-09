/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_device_service_discovery_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_device_service_discovery_rsp_handler(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bStack_3b;
  ushort uStack_3a;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  void *pvStack_24;
  
  if (param_1 == 0) {
    return 0xfe;
  }
  uVar1 = *(ushort *)(param_1 + 6);
  if (uVar1 == 0x8004) {
    memset(&uStack_38,0,0x18);
    iVar4 = *(int *)(param_1 + 0x14);
    pvVar3 = pvStack_24;
    if (iVar4 != 0) {
      uStack_3a = 0;
      bStack_3b = 0;
      uVar5 = zmsg_get_length(iVar4);
      af_read_le8_isra_0(iVar4,&uStack_3a,&uStack_38);
      af_read_le16_isra_0(iVar4,&uStack_3a,(int)&uStack_38 + 2);
      af_read_le8_isra_0(iVar4,&uStack_3a,&local_34);
      pvVar3 = pvStack_24;
      if ((int)((uint)uStack_3a + (local_34 & 0xff)) <= (int)uVar5) {
        if ((uStack_38 & 0xff) == 0) {
          af_read_le8_isra_0(iVar4,&uStack_3a,&uStack_30);
          af_read_le16_isra_0(iVar4,&uStack_3a,(int)&uStack_30 + 2);
          af_read_le16_isra_0(iVar4,&uStack_3a,&uStack_2c);
          af_read_le8_isra_0(iVar4,&uStack_3a,&bStack_3b);
          uStack_2c._0_3_ = CONCAT12(bStack_3b >> 4 | bStack_3b << 4,(undefined2)uStack_2c);
          af_read_le8_isra_0(iVar4,&uStack_3a,(int)&uStack_2c + 3);
          uVar6 = uStack_2c >> 0x18;
          pvStack_24 = calloc(uVar6,2);
          uVar7 = 0;
          if (pvStack_24 == (void *)0x0) {
            pvVar3 = (void *)0x0;
            if (uVar6 != 0) goto _L0;
          }
          else {
            for (; uVar7 < uStack_2c >> 0x18; uVar7 = uVar7 + 1 & 0xff) {
              af_read_le16_isra_0(iVar4,&uStack_3a,(void *)((int)pvStack_24 + uVar7 * 2));
            }
          }
          af_read_le8_isra_0(iVar4,&uStack_3a,&uStack_28);
          pvStack_24 = (void *)mm_realloc(pvStack_24,(uStack_2c >> 0x18) + ((uint)uStack_28 & 0xff),
                                          2);
          uVar6 = uStack_2c >> 0x18;
          if (pvStack_24 == (void *)0x0) {
            pvVar3 = pvStack_24;
            if (((uint)uStack_28 & 0xff) + uVar6 != 0) goto _L0;
          }
          else {
            for (; uVar6 < (uStack_2c >> 0x18) + ((uint)uStack_28 & 0xff); uVar6 = uVar6 + 1 & 0xff)
            {
              af_read_le16_isra_0(iVar4,&uStack_3a,(void *)((int)pvStack_24 + uVar6 * 2));
            }
          }
        }
        pvVar3 = pvStack_24;
        if (uStack_3a <= uVar5) {
          zdo_cb_address_rsp_isra_0(&uStack_38,param_1 + 8);
          uVar2 = 0;
          pvVar3 = pvStack_24;
          goto _L0;
        }
      }
    }
_L0:
    pvStack_24 = pvVar3;
    uVar2 = 0xfe;
    pvVar3 = pvStack_24;
    goto _L0;
  }
  if (uVar1 < 0x8005) {
    if (uVar1 == 0x8002) {
      iVar4 = *(int *)(param_1 + 0x14);
      uStack_38 = 0;
      local_34 = 0;
      uStack_30 = (void *)0x0;
      uStack_2c = 0;
      uStack_28 = (void *)0x0;
      if (iVar4 == 0) {
        return 0xfe;
      }
      uStack_3a = 0;
      uVar5 = zmsg_get_length(iVar4);
      af_read_le8_isra_0(iVar4,&uStack_3a,&uStack_38);
      af_read_le16_isra_0(iVar4,&uStack_3a,(int)&uStack_38 + 2);
      if (uVar5 < uStack_3a) {
        return 0xfe;
      }
      if ((uStack_38 & 0xff) != 0) {
        local_34 = 0;
        uStack_30 = (void *)0x0;
        uStack_2c = 0;
        uStack_28 = (void *)0x0;
        goto _L0;
      }
      af_read_le16_isra_0(iVar4,&uStack_3a);
      af_read_le8_isra_0(iVar4,&uStack_3a,(int)&local_34 + 2);
      af_read_le16_isra_0(iVar4,&uStack_3a,&uStack_30);
      af_read_le8_isra_0(iVar4,&uStack_3a,(int)&uStack_30 + 2);
      af_read_le16_isra_0(iVar4,&uStack_3a,&uStack_2c);
      af_read_le16_isra_0(iVar4,&uStack_3a,(int)&uStack_2c + 2);
      af_read_le16_isra_0(iVar4,&uStack_3a,&uStack_28);
      af_read_le8_isra_0(iVar4,&uStack_3a,(int)&uStack_28 + 2);
    }
    else {
      if (uVar1 != 0x8003) {
        if (1 < (ushort)(uVar1 + 0x8000)) {
          return 0x84;
        }
        uStack_38 = 0;
        local_34 = 0;
        uStack_30 = (void *)0x0;
        uStack_2c = 0;
        uStack_28 = (void *)0x0;
        if (*(int *)(param_1 + 0x14) != 0) {
          if (uVar1 == 0x8000) {
            iVar4 = zdo_op_nwk_addr_rsp(2,&uStack_38,0);
          }
          else {
            iVar4 = zdo_op_ieee_addr_rsp(2,&uStack_38,0);
          }
          if (iVar4 == 0) {
            uStack_3a = 0;
            nwk_address_update((int)&uStack_38 + 1,(uint)uStack_30 >> 0x10,&uStack_3a);
            zdo_cb_address_rsp_isra_0(&uStack_38,param_1 + 8);
            uVar2 = 0;
            pvVar3 = uStack_28;
            goto _L0;
          }
        }
        uVar2 = 0xfe;
        pvVar3 = uStack_28;
        goto _L0;
      }
      iVar4 = *(int *)(param_1 + 0x14);
      uStack_38 = 0;
      local_34 = local_34 & 0xffff0000;
      if (iVar4 == 0) {
        return 0xfe;
      }
      uStack_3a = 0;
      uVar5 = zmsg_get_length(iVar4);
      af_read_le8_isra_0(iVar4,&uStack_3a,&uStack_38);
      af_read_le16_isra_0(iVar4,&uStack_3a,(int)&uStack_38 + 2);
      if (uVar5 < uStack_3a) {
        return 0xfe;
      }
      if ((uStack_38 & 0xff) != 0) {
        local_34 = local_34 & 0xffff0000;
        goto _L0;
      }
      af_read_le16_isra_0(iVar4,&uStack_3a,&local_34);
    }
    if (uVar5 < uStack_3a) {
      return 0xfe;
    }
_L0:
    zdo_cb_address_rsp_isra_0(&uStack_38,param_1 + 8);
    return 0;
  }
  if (uVar1 != 0x8006) {
    if (uVar1 == 0x8015) {
      iVar4 = *(int *)(param_1 + 0x14);
      uStack_38 = 0;
      if (iVar4 == 0) {
        return 0xfe;
      }
      uStack_3a = 0;
      uVar5 = zmsg_get_length(iVar4);
      af_read_le8_isra_0(iVar4,&uStack_3a,&uStack_38);
      af_read_le16_isra_0(iVar4,&uStack_3a,(int)&uStack_38 + 2);
      if (uVar5 < uStack_3a) {
        return 0xfe;
      }
      if ((uStack_38 & 0x400000) != 0) {
        iVar4 = core_globals_get();
        *(undefined2 *)(iVar4 + 0x9dc) = *(undefined2 *)(param_1 + 4);
      }
      goto _L0;
    }
    if (uVar1 != 0x8005) {
      return 0x84;
    }
  }
  uStack_38 = 0;
  local_34 = 0;
  uStack_30 = (void *)0x0;
  iVar4 = *(int *)(param_1 + 0x14);
  if (iVar4 != 0) {
    uStack_3a = 0;
    uVar5 = zmsg_get_length(iVar4);
    af_read_le8_isra_0(iVar4,&uStack_3a,&uStack_38);
    af_read_le16_isra_0(iVar4,&uStack_3a,(int)&uStack_38 + 2);
    af_read_le8_isra_0(iVar4,&uStack_3a,&local_34);
    if (uStack_3a <= uVar5) {
      if (((uStack_38 & 0xff) == 0) && (uVar6 = local_34 & 0xff, uVar6 != 0)) {
        uStack_30 = calloc(uVar6,1);
        if ((uStack_30 == (void *)0x0) ||
           (af_read_bytes_isra_0(iVar4,&uStack_3a,uVar6,uStack_30), uVar5 < uStack_3a)) goto _L0;
      }
      else {
        uStack_30 = (void *)0x0;
      }
      zdo_cb_address_rsp_isra_0(&uStack_38,param_1 + 8);
      uVar2 = 0;
      pvVar3 = uStack_30;
      goto _L0;
    }
  }
_L0:
  uVar2 = 0xfe;
  pvVar3 = uStack_30;
_L0:
  if (pvVar3 != (void *)0x0) {
    mm_free();
  }
  return uVar2;
}

