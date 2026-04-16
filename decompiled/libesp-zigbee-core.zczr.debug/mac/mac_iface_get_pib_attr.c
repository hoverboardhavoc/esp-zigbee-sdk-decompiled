/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_iface_get_pib_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_iface_get_pib_attr
                    (mac_interface_t *iface,mac_pib_attr_t pib_attr,void *value,size_t value_size)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  byte bVar8;
  undefined3 in_register_0000202d;
  uint uVar9;
  undefined1 *puVar10;
  
  uVar9 = CONCAT31(in_register_0000202d,pib_attr);
  puVar10 = (undefined1 *)iface->dev;
  if (value == (void *)0x0) {
    return 2;
  }
  if (uVar9 == 0x52) {
    *(byte *)value = (byte)(*(uint *)(puVar10 + 0x28) >> 0x11) & 1;
    return 0;
  }
  if (0x52 < uVar9) {
    if (uVar9 == 0x5a) {
      *(undefined1 *)value = puVar10[0x1f];
      return 0;
    }
    if (0x5a < uVar9) {
      if (uVar9 == 0x61) {
        bVar8 = puVar10[0x44];
                    /* WARNING: Load size is inaccurate */
        *(uint *)value = *value & 0x7ffffff | (uint)bVar8 << 0x1b;
        *(uint *)value = (uint)bVar8 << 0x1b | 1 << ((byte)puVar10[0x43] & 0x1f) & 0x7ffffffU;
        return 0;
      }
      if (uVar9 < 0x62) {
        if (uVar9 == 0x5d) {
          *(undefined4 *)value = 0;
          return 0;
        }
        if (uVar9 == 0x60) {
          bVar8 = puVar10[0x42];
                    /* WARNING: Load size is inaccurate */
          *(uint *)value = *value & 0x7ffffff | (uint)bVar8 << 0x1b;
          *(uint *)value = (uint)bVar8 << 0x1b | 1 << ((byte)puVar10[0x41] & 0x1f) & 0x7ffffffU;
          return 0;
        }
        return 500;
      }
      if (uVar9 == 0x62) {
        if ((puVar10[0x9c] & 2) != 0) {
          bVar8 = puVar10[0x42];
                    /* WARNING: Load size is inaccurate */
          *(uint *)value = *value & 0x7ffffff | (uint)bVar8 << 0x1b;
          *(uint *)value = (uint)bVar8 << 0x1b | 1 << ((byte)puVar10[0x41] & 0x1f) & 0x7ffffffU;
          return 0;
        }
        *(undefined4 *)value = 0;
        return 0;
      }
      if (uVar9 == 99) {
        *(undefined4 *)value = *(undefined4 *)(puVar10 + 0x18);
        return 0;
      }
      return 500;
    }
    if (uVar9 == 0x57) {
      *(undefined1 *)value = puVar10[0x21];
      return 0;
    }
    if (0x57 < uVar9) {
      if (uVar9 == 0x58) {
        *(undefined2 *)value = *(undefined2 *)(puVar10 + 0x1c);
        return 0;
      }
      if (uVar9 == 0x59) {
        *(undefined1 *)value = puVar10[0x1e];
        return 0;
      }
      return 500;
    }
    if (uVar9 == 0x54) {
      *(undefined4 *)value = 0xf;
      return 0;
    }
    if (uVar9 != 0x55) {
      if (uVar9 == 0x53) {
        *(undefined2 *)value = *(undefined2 *)(puVar10 + 8);
        return 0;
      }
      return 500;
    }
    *(undefined2 *)value = *(undefined2 *)(puVar10 + 0x28);
    return 0;
  }
  if (uVar9 == 0x4a) {
    uVar1 = puVar10[0x11];
    uVar2 = puVar10[0x12];
    uVar3 = puVar10[0x13];
    uVar4 = puVar10[0x14];
    uVar5 = puVar10[0x15];
    uVar6 = puVar10[0x16];
    uVar7 = puVar10[0x17];
    *(undefined1 *)value = puVar10[0x10];
    *(undefined1 *)((int)value + 1) = uVar1;
    *(undefined1 *)((int)value + 2) = uVar2;
    *(undefined1 *)((int)value + 3) = uVar3;
    *(undefined1 *)((int)value + 4) = uVar4;
    *(undefined1 *)((int)value + 5) = uVar5;
    *(undefined1 *)((int)value + 6) = uVar6;
    *(undefined1 *)((int)value + 7) = uVar7;
    return 0;
  }
  if (0x4a < uVar9) {
    if (uVar9 == 0x4e) {
      *(undefined1 *)value = puVar10[0x22];
      return 0;
    }
    if (uVar9 < 0x4f) {
      if (uVar9 == 0x4b) {
        *(undefined2 *)value = *(undefined2 *)(puVar10 + 0xe);
        return 0;
      }
      if (uVar9 == 0x4c) {
        *(undefined1 *)value = puVar10[0xc];
        return 0;
      }
      return 500;
    }
    if (uVar9 == 0x4f) {
      *(undefined1 *)value = puVar10[0x20];
      return 0;
    }
    if (uVar9 == 0x50) {
      *(undefined2 *)value = *(undefined2 *)(puVar10 + 10);
      return 0;
    }
    return 500;
  }
  if (uVar9 == 0x46) {
    *(undefined1 *)value = puVar10[0x23];
    return 0;
  }
  if (0x46 < uVar9) {
    if (uVar9 == 0x47) {
      *(undefined4 *)value = 0xf;
      return 0;
    }
    if (uVar9 == 0x49) {
      *(undefined1 *)value = puVar10[0xd];
      return 0;
    }
    return 500;
  }
  if (uVar9 == 0x41) {
    *(byte *)value = (byte)*(undefined2 *)(puVar10 + 0x2a) & 1;
    return 0;
  }
  if (uVar9 != 0x45) {
    if (uVar9 == 0x40) {
      uVar1 = puVar10[1];
      uVar2 = puVar10[2];
      uVar3 = puVar10[3];
      uVar4 = puVar10[4];
      uVar5 = puVar10[5];
      uVar6 = puVar10[6];
      uVar7 = puVar10[7];
      *(undefined1 *)value = *puVar10;
      *(undefined1 *)((int)value + 1) = uVar1;
      *(undefined1 *)((int)value + 2) = uVar2;
      *(undefined1 *)((int)value + 3) = uVar3;
      *(undefined1 *)((int)value + 4) = uVar4;
      *(undefined1 *)((int)value + 5) = uVar5;
      *(undefined1 *)((int)value + 6) = uVar6;
      *(undefined1 *)((int)value + 7) = uVar7;
      return 0;
    }
    return 500;
  }
  *(undefined4 *)value = *(undefined4 *)(puVar10 + 0x24);
  return 0;
}

