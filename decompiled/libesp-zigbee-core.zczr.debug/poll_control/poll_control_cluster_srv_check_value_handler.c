/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
poll_control_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  short sVar1;
  bool bVar2;
  ezb_zcl_status_t eVar3;
  undefined2 in_register_0000202a;
  int iVar4;
  undefined3 in_register_0000202d;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  
  uVar5 = CONCAT31(in_register_0000202d,endpoint);
  uVar7 = CONCAT22(in_register_0000202a,attr_id);
  if (value == (void *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/poll_control.c",0xfa,
                  "poll_control_cluster_srv_check_value_handler","value");
_L0:
    eVar3 = '\0';
  }
  else {
    if (uVar7 == 2) {
                    /* WARNING: Load size is inaccurate */
      sVar1 = *value;
      bVar2 = sVar1 != 0;
      iVar4 = zcl_get_attr_desc(uVar5,0x20,1,0);
      if (iVar4 != 0) {
        if (sVar1 == 0) {
          return 0x87;
        }
                    /* WARNING: Load size is inaccurate */
        if ((uint)*value <= **(uint **)(iVar4 + 8)) {
          return '\0';
        }
        return 0x87;
      }
    }
    else if (uVar7 < 3) {
      if (uVar7 == 0) {
                    /* WARNING: Load size is inaccurate */
        uVar7 = *value;
        if (uVar7 == 0) {
          return '\0';
        }
        bVar2 = uVar7 < 0x6e0001;
        iVar4 = zcl_get_attr_desc(uVar5,0x20,1,4,0);
        if (iVar4 != 0) {
          if (uVar7 < 0x6e0001) {
                    /* WARNING: Load size is inaccurate */
            if (*value < **(uint **)(iVar4 + 8)) {
              bVar2 = false;
            }
            else {
              bVar2 = true;
            }
          }
          else {
            bVar2 = false;
          }
        }
        iVar4 = zcl_get_attr_desc(uVar5,0x20,1,0);
        if (iVar4 != 0) {
          if (!bVar2) {
            return 0x87;
          }
                    /* WARNING: Load size is inaccurate */
          if (**(uint **)(iVar4 + 8) <= *value) {
            return '\0';
          }
          return 0x87;
        }
      }
      else {
        if (uVar7 != 1) goto _L0;
                    /* WARNING: Load size is inaccurate */
        iVar6 = *value;
        bVar2 = iVar6 - 4U < 0x6dfffd;
        iVar4 = zcl_get_attr_desc(uVar5,0x20,1,5,0);
        if (iVar4 != 0) {
          if (iVar6 - 4U < 0x6dfffd) {
                    /* WARNING: Load size is inaccurate */
            if (*value < **(uint **)(iVar4 + 8)) {
              bVar2 = false;
            }
            else {
              bVar2 = true;
            }
          }
          else {
            bVar2 = false;
          }
        }
        iVar4 = zcl_get_attr_desc(uVar5,0x20,1,0,0);
        if (iVar4 != 0) {
          if (bVar2) {
                    /* WARNING: Load size is inaccurate */
            if (**(uint **)(iVar4 + 8) < *value) {
              bVar2 = false;
            }
            else {
              bVar2 = true;
            }
          }
          else {
            bVar2 = false;
          }
        }
        iVar4 = zcl_get_attr_desc(uVar5,0x20,1,2,0);
        if (iVar4 != 0) {
          if (!bVar2) {
            return 0x87;
          }
                    /* WARNING: Load size is inaccurate */
          if ((uint)**(ushort **)(iVar4 + 8) <= *value) {
            return '\0';
          }
          return 0x87;
        }
      }
    }
    else {
      if (uVar7 != 3) {
        return '\0';
      }
                    /* WARNING: Load size is inaccurate */
      sVar1 = *value;
      bVar2 = sVar1 != 0;
      iVar4 = zcl_get_attr_desc(uVar5,0x20,1,6,0);
      if (iVar4 != 0) {
        if (sVar1 == 0) {
          return 0x87;
        }
                    /* WARNING: Load size is inaccurate */
        if (*value <= **(ushort **)(iVar4 + 8)) {
          return '\0';
        }
        return 0x87;
      }
    }
    if (bVar2) {
      eVar3 = '\0';
    }
    else {
      eVar3 = 0x87;
    }
  }
  return eVar3;
}

